/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     int n, m;

     while ((cin >> n >> m) && (n != 0 || m != 0))
     {
          priority_queue<int> dragonHeads;

          for (int i = 0; i < n; i++)
          {
               int aux;

               cin >> aux;
               aux = -aux;
               dragonHeads.push(aux);
          }

          priority_queue<int> knights;

          for (int i = 0; i < m; i++)
          {
               int aux;

               cin >> aux;
               aux = -aux;
               knights.push(aux);
          }

          if (m < n)
          {
               cout << "Loowater is doomed!" << endl;
          }
          else
          {
               long money;

               money = 0;

               for (int i = 0; i < m && !dragonHeads.empty(); i++)
               {
                    if (abs(knights.top()) >= abs(dragonHeads.top()))
                    {
                         money += abs(knights.top());
                         dragonHeads.pop();
                    }

                    knights.pop();
               }

               if (dragonHeads.empty())
               {
                    cout << money << endl;
               }
               else
               {
                    cout << "Loowater is doomed!" << endl;
               }
          }
     }

     return 0;
}