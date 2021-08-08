#include <bits/stdc++.h>
#define MAX_LINE 51

using namespace std;

bool dfs(int n, int m, vector<vector<char>> grid, int row, int col, char color, int previousRow, int previousCol, vector<pair<int, int>> directions, vector<vector<bool>> *visited)
{
    if (row < 0 || row >= n || col < 0 || col >= m)
    {
        return false;
    }
    else if (grid[row][col] != color)
    {
        return false;
    }

    if ((*visited)[row][col])
    {
        return true;
    }

    (*visited)[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
        int auxRow, auxCol;

        auxRow = row + directions[i].first;
        auxCol = col + directions[i].second;

        if (auxRow != previousRow || auxCol != previousCol)
        {
            if (dfs(n, m, grid, auxRow, auxCol, color, row, col, directions, visited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<char>> grid(MAX_LINE, vector<char>(MAX_LINE));
    vector<vector<bool>> visited(MAX_LINE, vector<bool>(MAX_LINE, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> directions = {pair<int, int>(1, 0),
                                         pair<int, int>(0, 1),
                                         pair<int, int>(-1, 0),
                                         pair<int, int>(0, -1)};
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                if (dfs(n, m, grid, i, j, grid[i][j], -1, -1, directions, &visited))
                {
                    flag = true;

                    break;
                }
            }
        }

        if (flag == true)
        {
            break;
        }
    }

    if (flag == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
