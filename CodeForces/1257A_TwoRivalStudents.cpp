/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void verificaPosicoes(int *rival1, int *rival2, int numEstudantes, int numTrocas)
{
     if ((*rival1 + numTrocas) <= numEstudantes)
     {
          *rival1 += numTrocas;
     }
     else if ((*rival1 + numTrocas) > numEstudantes)
     {
          int aux = *rival1;
          *rival1 = numEstudantes;
          *rival2 -= ((aux + numTrocas) - numEstudantes);
          if (*rival2 < 1)
          {
               *rival2 = 1;
          }
     }
}

int main(){

     //Casos de Testes
     int casosTeste;
     cin >> casosTeste;
     while (casosTeste--)
     {
          int numEstudantes, numTrocas, posRival1, posRival2;
          cin >> numEstudantes >> numTrocas >> posRival1 >> posRival2;

          if (numTrocas > 0)
          {
               if (posRival1 > posRival2)
               {
                    verificaPosicoes(&posRival1, &posRival2, numEstudantes, numTrocas);
                    cout << posRival1 - posRival2 << endl;
               }
               else
               {
                    verificaPosicoes(&posRival2, &posRival1, numEstudantes, numTrocas);
                    cout << posRival2 - posRival1 << endl;
               }
          }
          else
          {
               cout << abs(posRival2 - posRival1) << endl;
          }
     }

     return 0;
}