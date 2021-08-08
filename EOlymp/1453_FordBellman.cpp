#include <bits/stdc++.h>
#define MAX 100

using namespace std;

vector<tuple<int, int, int>> edgeList;

vector<int> bellmanFord(int start, int N, int M){
    vector<int> distance (MAX + 1);

    for(int i = 1; i <= N; i++){
        distance[i] = INT_MAX;
    }

    distance[start] = 0;

    for(int i = 1; i < N; i++){
        for(int j = 0; j < M; j++){
            int from, to, weight;

            tie(from, to, weight) = edgeList[j];

            if(distance[from] != INT_MAX && distance[from] + weight < distance[to]){
                distance[to] = distance[from] + weight;
            }
        }
    }

    return distance;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int from, to, weight;

        cin >> from >> to >> weight;

        edgeList.push_back({from, to, weight});
    }

    vector<int> distance;

    distance = bellmanFord(1, N, M);

    cout << distance[1];

    for(int i = 2; i <= N; i++){
        cout << " ";
        
        if(distance[i] == INT_MAX){
            cout << 30000;
        }
        else{
            cout << distance[i];
        }
    }

    cout << endl;

    return 0;
}