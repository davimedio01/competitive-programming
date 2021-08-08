#include <bits/stdc++.h>
#define MAX 50

using namespace std;

long long bfs(vector<int> g[], int start, vector<bool> &visited)
{
    queue<int> q;
    long long mult = 1;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node;

        node = q.front();
        q.pop();

        for (int i = 0; i < g[node].size(); i++)
        {
            int to = g[node][i];

            if (!visited[to])
            {
                mult *= 2;
                visited[to] = true;

                q.push(to);
            }
        }
    }

    return mult;
}

int main()
{
    int N, M;

    cin >> N >> M;

    vector<int> g[MAX + 1];

    for (int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> visited(MAX + 1, false);
    long long mult = 1;

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            mult *= bfs(g, i, visited);
        }
    }

    cout << mult << endl;

    return 0;
}