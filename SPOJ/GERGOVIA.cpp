/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O valor do "trabalho total", como as casas estão a uma mesma distância,
pode ser dado pela soma do módulo do valor anterior, 
sendo que o atual será mudado pela soma do anterior com ele mesmo.

Por exemplo:

5 -4 1 -3 1
{5} [1] 1 -3 1 -> 5 trabalhos
5 {1} [2] -3 1 -> 6 trabalhos
5 1 {2} [-1] 1 -> 8 trabalhos
5 1 2 {-1} [0] -> 9 trabalhos
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     //Casos de Teste
     long int testes;
     while(cin >> testes){
          if(testes == 0)
               break;
          
          //Vector salvando o total
          vector<long int> entrega;

          //Auxiliar
          int qtd;
          //Salvando as quantidades
          for(long int i = 1; i <= testes; i++){
               cin >> qtd;
               entrega.push_back(qtd);
          }

          //Soma Final do Trabalho
          long long int soma_final = 0;
          for(long int i = 1; i < testes; i++){
               //Somando as entregas
               entrega[i] += entrega[i-1];
               //A soma total dos "trabalhos" será dada pela soma dos valores anteriores
               soma_final += fabs(entrega[i-1]);
          }
          cout << soma_final << endl;

         
     }
     
     return 0;
}