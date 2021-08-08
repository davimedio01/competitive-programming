#include <bits/stdc++.h>
#define MAX_NODES 10000

using namespace std;

vector<tuple<long, int, int>> treeEdges(MAX_NODES + 1);
vector<int> link(MAX_NODES + 1);
vector<int> setSize(MAX_NODES + 1);

int findSet(int node)
{
     while (node != link[node])
     {
          node = link[node];
     }

     return node;
}

void uniteSet(int node1, int node2)
{
     node1 = findSet(node1);
     node2 = findSet(node2);

     if (setSize[node1] < setSize[node2])
     {
          swap(node1, node2);
     }

     setSize[node1] += setSize[node2];

     link[node2] = node1;
}

bool sameSet(int node1, int node2)
{
     return findSet(node1) == findSet(node2);
}

long long kruskal(int N, long int M, vector<tuple<long, int, int>> treeEdges)
{
     sort(treeEdges.begin(), treeEdges.end());

     long long maxWeight;

     maxWeight = 0;

     for (int i = 1; i <= N; i++)
     {
          link[i] = i;
          setSize[i] = 1;
     }

     for (vector<tuple<long int, int, int>>::iterator it = treeEdges.begin(); it != treeEdges.end(); it++)
     {
          int node1, node2;

          node1 = get<1>(*it);
          node2 = get<2>(*it);

          if (!sameSet(node1, node2))
          {
               uniteSet(node1, node2);

               maxWeight += get<0>(*it);
          }
     }

     return maxWeight;
}

int main()
{
     int N;
     long M;

     cin >> N >> M;

     for (int i = 0; i < M; i++)
     {
          int aux1, aux2, aux3;

          cin >> aux1 >> aux2 >> aux3;
          treeEdges.push_back({aux3, aux1, aux2});
     }

     cout << kruskal(N, M, treeEdges) << endl;

     return 0;
}
