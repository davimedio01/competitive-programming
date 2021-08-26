#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> point;

int main()
{
     int n, max = 0;
     point p;

     cin >> n;

     for (int i = 0; i < n; i++)
     {
          cin >> p.first >> p.second;

          if (p.first + p.second > max)
          {
               max = p.first + p.second;
          }
     }

     cout << max << endl;

     return 0;
}