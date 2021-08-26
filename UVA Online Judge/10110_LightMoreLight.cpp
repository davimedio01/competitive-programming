/*
https://medium.com/consol/light-more-light-uva-10110-8adfbe86a68f

Algumas coisas a levar em consideração:

- Mabu vai no corredor "n" vezes com "n" lâmpadas (1 <= N)
- A última lâmpada não será ligada/desligada novamente (ele vai, muda a condição, e volta)
- A "n" lâmpada será ligada/desligada com base no número de seus fatores positivos (representado pela "i" divisão)

Ou seja: necessário encontrar o número de fatores positivos de "n" (divisores)

A "n" lâmpada será ligada quando o num de fatores positivos de "n" for ímpar, e será desligada quando for par
Ou seja: basta analisar se o "n" é um quadrado perfeito.

*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     unsigned long long bulb;
     while(cin >> bulb)
     {
          if(bulb == 0){
               break;
          }

          //Analisando se é um qudrado perfeito
          if(sqrt(bulb) == ceil(sqrt(bulb)))
          {
               cout << "yes" << endl;
          }
          else
          {
               cout << "no" << endl;
          }
     }
     
     return 0;
}