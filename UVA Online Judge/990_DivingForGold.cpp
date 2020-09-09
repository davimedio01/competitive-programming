#include <bits/stdc++.h>

#define MAX_TREASURES 30
#define MAX_DEPTH 1000

using namespace std;

int knapsack(vector<vector<int>> *table, vector<int> dive, vector<int> treasure, int n, int t)
{
    for (int i = 0; i <= n; i++)
    {
        (*table)[i][0] = 0;
    }

    for (int i = 0; i <= t; i++)
    {
        (*table)[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (dive[i] > j)
            {
                (*table)[i][j] = (*table)[i - 1][j];
            }
            else
            {
                (*table)[i][j] = max((*table)[i - 1][j - dive[i]] + treasure[i], (*table)[i - 1][j]);
            }
        }
    }

    return (*table)[n][t];
}

int main()
{
    int t, w;
    bool flag = false;

    while (cin >> t >> w)
    {
        int n;

        cin >> n;

        vector<int> depth(MAX_DEPTH + 1, 0);
        vector<int> dive(MAX_TREASURES + 1, 0);
        vector<int> treasure(MAX_TREASURES + 1, 0);
        vector<vector<int>> table(MAX_TREASURES + 1, vector<int>(MAX_DEPTH + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            cin >> depth[i] >> treasure[i];
            dive[i] = 3 * (w * depth[i]);
        }

        int maxGold;

        maxGold = knapsack(&table, dive, treasure, n, t);

        int treasureCount;
        stack<pair<int, int>> divesMade;

        treasureCount = 0;

        while (n >= 1)
        {
            if (table[n][t] != table[n - 1][t])
            {
                divesMade.push(pair<int, int>(depth[n], treasure[n]));
                treasureCount++;

                t -= dive[n];
            }

            n--;
        }

        if (flag)
        {
            cout << endl;
        }

        flag = true;

        cout << maxGold << endl
             << treasureCount << endl;

        while (!divesMade.empty())
        {
            cout << divesMade.top().first << " " << divesMade.top().second << endl;
            divesMade.pop();
        }
    }

    return 0;
}