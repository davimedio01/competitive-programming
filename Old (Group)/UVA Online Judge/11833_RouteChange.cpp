//Criado por Luis Henrique Morelli - 27/05/2020 às 23:20

#include <bits/stdc++.h>

#define MAX_CITIES 250

using namespace std;

int dijkstra(int C, int SR, int RC, vector<pair<int, int>> connections[])
{
    int distance[MAX_CITIES];

    for (int i = 0; i < C; i++)
    {
        distance[i] = INT_MAX;
    }

    distance[RC] = 0;

    priority_queue<pair<int, int>> q;
    bool processed[MAX_CITIES];

    for (int i = 0; i < C; i++)
    {
        processed[i] = false;
    }

    q.push({0, RC});

    while (!q.empty())
    {
        int node1;

        node1 = q.top().second;
        q.pop();

        if (processed[node1])
        {
            continue;
        }

        processed[node1] = true;

        for (int i = 0; i < connections[node1].size(); i++)
        {
            int node2, length;

            node2 = connections[node1][i].first;

            if (node1 < SR && node2 != node1 + 1)
            {
                continue;
            }

            length = connections[node1][i].second;

            if (distance[node1] + length < distance[node2])
            {
                distance[node2] = distance[node1] + length;

                q.push({-distance[node2], node2});
            }
        }
    }

    return distance[SR - 1];
}

int main()
{
    int C, R, SR, RC;

    while (cin >> C >> R >> SR >> RC)
    {
        if (C == 0 && R == 0 && SR == 0 && RC == 0)
        {
            break;
        }

        vector<pair<int, int>> connections[MAX_CITIES];

        for (int i = 0; i < R; i++)
        {
            int aux1, aux2, aux3;

            cin >> aux1 >> aux2 >> aux3;
            connections[aux1].push_back({aux2, aux3});
            connections[aux2].push_back({aux1, aux3});
        }

        cout << dijkstra(C, SR, RC, connections) << endl;
    }

    return 0;
}