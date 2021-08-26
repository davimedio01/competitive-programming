/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
     return a.first < b.first;
}

int findMax(int n, vector<pair<int, int>> activities)
{
     pair<int, int> prev = activities[0];
     int count = 1;

     for (int i = 1; i < n; i++)
     {
          if ((activities[i].first >= prev.first && activities[i].second <= prev.second) || activities[i].first >= prev.second)
          {
               if (activities[i].first >= prev.second)
               {
                    count++;
               }

               prev = activities[i];
          }
     }

     return count;
}

int main(){

     int T, N, m, n;
     vector<pair<int, int>> activities;

     cin >> T;

     while (T--)
     {
          cin >> N;

          activities.clear();

          for (int i = 0; i < N; i++)
          {
               cin >> m >> n;

               activities.push_back(make_pair(m, n));
          }

          sort(activities.begin(), activities.end(), compare);

          cout << findMax(N, activities) << endl;
     }

     return 0;
}