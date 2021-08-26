/**/

#include <bits/stdc++.h>
#include <iostream>

#define MAX_I 2147483649
#define MAXLENGHT 31270

using namespace std;

void binarySearch(string sequencia, vector<long long> soma_dig, long long digito)
{
     int esq, dir, meio;

     esq = 0;
     dir = MAXLENGHT;

     while (esq <= dir)
     {
          meio = (esq + dir) / 2;

          if (soma_dig[meio] < digito)
          {
               if (soma_dig[meio + 1] >= digito)
               {
                    break;
               }

               esq = meio + 1;
          }
          else
          {
               dir = meio - 1;
          }
     }

     cout << sequencia[digito - soma_dig[meio] - 1] << endl;
}

int main(){

     string sequencia;
     vector<long long> soma_dig;
     long long aux = 0;

     soma_dig.push_back(0);

     stringstream ss;
     for (long long i = 1; i <= MAXLENGHT; i++)
     {
          //ss << i;
          sequencia.append(to_string(i));
          //sequencia.append(ss.str());
          //ss.clear(); ss.str(string());

          aux += log10(i) + 1;
          soma_dig.push_back(aux + soma_dig[i - 1]);
     }

     long long casos;
     cin >> casos;
     while(casos--)
     {
          long long digito;
          cin >> digito;

          binarySearch(sequencia, soma_dig, digito);
     }

     return 0;
}
