/*
“Every perfect square(x2) always have only odd numbers of factors“
Para ser um Triple-Prime, é necessário o número ser um quadrado perfeito de um número primo

Ou seja:

1) verificar se o número é um quadrado perfeito
2) caso seja, verificar se sua raiz é um número primo

*Uso do conceito de Crivo de Erástones
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX_RAIZ 1e6

vector<bool> Crivo_Erastones(MAX_RAIZ + 1, true);
void CriaErastones()
{
     Crivo_Erastones[0] = Crivo_Erastones[1] = false;
     for(long long i = 2; i*i <= MAX_RAIZ; i++)
     {
          if(Crivo_Erastones[i] == true)
          {
               for(long long j = i*i; j <= MAX_RAIZ; j += i){
                    Crivo_Erastones[j] = false;
               }
          }
     }
}

//Verificar se é quadrado perfeito
bool VerificaQuadradoPerfeito(long long num)
{
     return ((sqrt(num) == ceil(sqrt(num))) ? true : false);
}

//Verifica se a raiz é um número primo
bool VerificaRaizNumPrimo(long long num)
{   
     return (Crivo_Erastones[num] == true ? true : false);
}



int main(){

     CriaErastones();

     long long casos;
     long long num;

     cin >> casos;

     for(long long i = 0; i < casos; i++)
     {
          cin >> num;

          //Verificando se o número é um quadrado perfeito
          if (VerificaQuadradoPerfeito(num))
          {
               //Caso seja, verificar se sua raiz é um número primo
               if (VerificaRaizNumPrimo(sqrt(num)))
               {
                    cout << "YES" << endl;
               }
               else
               {
                    cout << "NO" << endl;
               }
               
          }
          else
          {
               cout << "NO" << endl;
          }
     }
     
     return 0;
}