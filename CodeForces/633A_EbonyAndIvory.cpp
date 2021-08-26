#include <bits/stdc++.h>
#define MAX_INTEREST 10

using namespace std;

int main()
{
     int a, b, c;

     cin >> a >> b >> c;

     if (c == a || c == b)
     {
          cout << "Yes" << endl;
     }
     else
     {
          while (c > 0)
          {
               if (c % b == 0)
               {
                    c %= b;

                    break;
               }

               c -= a;
          }

          if (c == 0)
          {
               cout << "Yes" << endl;
          }
          else
          {
               cout << "No" << endl;
          }
     }

     return 0;
}
