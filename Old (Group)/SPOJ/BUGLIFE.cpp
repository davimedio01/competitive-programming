#include <bits/stdc++.h>

#define MAX 2000

using namespace std;

bool bicoloring(vector<vector<long>> graph, long N, long start, vector<bool> &visited){
    vector<long> d (MAX + 1);
    vector<long> c (MAX + 1);

    for(long i = 1; i <= N; i++){
        d[i] = 0;
        c[i] = 0;
    }

    queue<long> q;

    q.push(start);

    while(!q.empty()){
        long v;

        v = q.front();
        q.pop();

        visited[v] = true;

        for(int i = 0; i < graph[v].size(); i++){
            int node;

            node = graph[v][i];
            
            if(d[node] == 0){
                d[node] += d[v] + 1;
                c[node] = d[node] % 2;

                q.push(node);
            }
            else if(c[node] == c[v]){
                return true;
            }
        }
    }

    return false;
}

vector<vector<long>> readGraph(long M){
    vector<vector<long>> adjList (MAX + 1);

    for(long i = 0; i < M; i++){
        long a, b;
        
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }   

    return adjList;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    int T;

    cin >> T;

    for(int i = 1; i <= T; i++){
        long N, M;
    
        cin >> N >> M;

        vector<vector<long>> adjList (MAX + 1);
        vector<bool> visited (MAX + 1, false);
        bool flag;

        adjList = readGraph(M);

        cout << "Scenario #" << i << ":" << endl;

        for(long j = 1; j <= N; j++){
            if(!visited[j]){
                flag = bicoloring(adjList, N, j, visited);
            }

            if(flag){
                cout << "Suspicious bugs found!" << endl;

                break;
            }
        }

        if(!flag){
            cout << "No suspicious bugs found!" << endl;
        }
    }

    return 0;
}