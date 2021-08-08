/**/

#include <bits/stdc++.h>
#include <iostream>

#define MAX 2001

using namespace std;

int memo[MAX][MAX] = {};
int findOptimalMax(int left, int right, int age, const vector<int> &prices);

int main()
{
     int N, value;
     vector<int> prices;

     cin >> N;

     for (int i = 0; i < N; i++)
     {
          cin >> value;

          prices.push_back(value);
     }

     cout << findOptimalMax(0, N - 1, 1, prices) << endl;

     return 0;
}

int findOptimalMax(int left, int right, int age, const vector<int> &prices)
{
     if (left > right)
     {
          return 0;
     }
     else if (left == right)
     {
          return age * prices[left];
     }

     if (memo[left + 1][right] == 0)
     {
          memo[left + 1][right] = findOptimalMax(left + 1, right, age + 1, prices);
     }

     if (memo[left][right - 1] == 0)
     {
          memo[left][right - 1] = findOptimalMax(left, right - 1, age + 1, prices);
     }

     int a = age * prices[left] + memo[left + 1][right];
     int b = age * prices[right] + memo[left][right - 1];

     return max(a, b);
}