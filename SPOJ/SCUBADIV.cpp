/**/

#include <bits/stdc++.h>
#include <iostream>

#define UPR_BOUND 1000000000
#define MAX_NUM 1001
#define MAX_OXY 22
#define MAX_NIT 80

using namespace std;

typedef struct{
    int oxy;
    int nit;
    int wt;
}info;

int findMin(int oxy, int nit, int n, const info (&cylinders)[MAX_NUM]);

int main()
{
     int c, t, a, n;

     cin >> c;

     for (int i = 0; i < c; i++)
     {
          cin >> t >> a >> n;

          info cylinders[MAX_NUM];

          for (int j = 1; j <= n; j++)
          {
               cin >> cylinders[j].oxy >> cylinders[j].nit >> cylinders[j].wt;
          }

          cout << findMin(t, a, n, cylinders) << endl;
     }

     return 0;
}

int findMin(int oxy, int nit, int n, const info (&cylinders)[MAX_NUM])
{
     int dp[MAX_NUM][MAX_OXY][MAX_NIT], i, j, k;

     for (i = 0; i <= n; i++)
     {
          for (j = 0; j <= oxy; j++)
          {
               for (k = 0; k <= nit; k++)
               {
                    if (j == 0 && k == 0)
                    {
                         dp[i][j][k] = 0;
                    }
                    else if (i == 0)
                    {
                         dp[i][j][k] = UPR_BOUND;
                    }
                    else
                    {
                         dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][max(j - cylinders[i].oxy, 0)][max(k - cylinders[i].nit, 0)] + cylinders[i].wt);
                    }
               }
          }
     }

     return dp[n][oxy][nit];
}