/**/

#include <bits/stdc++.h>
#include <iostream>

#define MAX_OLIVES pow(10, 4)

using namespace std;

int main(){

     long C, N;
     vector<long> olives(MAX_OLIVES, 0);

     while (cin >> C >> N)
     {
          for (int i = 0; i < N; i++)
          {
               cin >> olives[i];
          }

          olives[N] = olives[0] + C;

          long tamSlices;
          bool flag1;

          tamSlices = C / N;
          flag1 = false;

          for (long i = olives[0]; i < olives[1]; i++)
          {
               long position;
               bool flag2;

               position = i;
               flag2 = true;

               for (long j = 1; j <= N; j++)
               {
                    if (olives[j] > position && olives[j] <= position + tamSlices)
                    {
                         position += tamSlices;
                    }
                    else
                    {
                         flag2 = false;

                         break;
                    }
               }

               if (flag2)
               {
                    flag1 = true;

                    break;
               }
          }

          if (flag1)
          {
               cout << "S" << endl;
          }
          else
          {
               cout << "N" << endl;
          }
     }

     return 0;
}