#include <bits/stdc++.h>
#include <iostream>

#define MAX_LENGTHS 3

using namespace std;

bool cutRibbon(int n, const vector<int> &lengths, long *cuts)
{
     if (n == 0)
     {
          return true;
     }

     for (int i = 0; i < MAX_LENGTHS; i++)
     {
          if (lengths[i] <= n)
          {
               (*cuts)++;
               n -= lengths[i];

               if (cutRibbon(n, lengths, cuts))
               {
                    return true;
               }

               (*cuts)--;
               n += lengths[i];
          }
     }

     return false;
}

int main(){

     int n;
     vector<int> lengths;

     cin >> n;

     for (int i = 0; i < MAX_LENGTHS; i++)
     {
          int aux;

          cin >> aux;

          bool flag;

          flag = false;

          for (int j = 0; j < lengths.size(); j++)
          {
               if (aux == lengths[j])
               {
                    flag = true;

                    break;
               }
          }

          if (flag == false)
          {
               lengths.push_back(aux);
          }
     }

     sort(lengths.begin(), lengths.end());

     long cuts, maxCuts;

     maxCuts = 0;

     cutRibbon(n, lengths, &maxCuts);

     do
     {
          cuts = 0;

          cutRibbon(n, lengths, &cuts);

          if (cuts > maxCuts)
          {
               maxCuts = cuts;
          }
     } while (next_permutation(lengths.begin(), lengths.end()));

     cout << maxCuts << endl;

     return 0;
}