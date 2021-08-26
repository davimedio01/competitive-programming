/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     long long n;
     cin >> n;

     vector<long long> flores;

     long long aux;
     for (long long i = 0; i < n; i++)
     {
          cin >> aux;

          flores.push_back(aux);
     }
     
     sort(flores.begin(), flores.end());
     
     long long diferenca = flores[n - 1] - flores[0];

     long long cont_menor = 1, cont_maior = 1;
     if(flores[0] == flores[n - 1])
     {
          //N * (N-1)/2! (permutação com repetição)
          cout << diferenca << " " << n * (n - 1) / 2 << endl;
     }
     else
     {
          long long j = n - 1;
          for (long long i = 1; i < j; i++)
          {
               if (flores[i] == flores[0])
               {
                    cont_menor++;
               }
               if (flores[j - i] == flores[n - 1])
               {
                    cont_maior++;
               }
          }

          cout << diferenca << " " << cont_menor * cont_maior << endl;
     }

     
     return 0;
}