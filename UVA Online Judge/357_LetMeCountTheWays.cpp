/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
Baseado no algoritmo do problema da mochila,
utiliza-se de um vetor contendo todos os valores do dinheiro
(cube[]) possíveis. Então é utilizado outro vetor auxilar
(mochila[]) contendo todos os resultados possíveis para a soma
de valores de dentro do cube[] dar N (usuário digitar).

Primeiramente, é necessário dar o valor da posição 0 do
vetor auxiliar, já que utiliza-se as posições reais do 
vetor dinheiro (cube[]) para calcular as 
combinações possíveis (ex. cube[1] = 1*1*1;
cube[2] = 2*2*2;...) por meio de dois laços for
(construção de uma "matriz", assim como no algoritmo
do problema da mochila). Como na posição 0 seria como 
"a soma N dar 0", então indica-se com valor 1 
(pois 0*0*0=0, tem-se somente uma forma de dar esse valor).
O índice i controla o valor das moedas (cube[i]) e o
índice j controla o vetor auxiliar (como forma de matriz), 
para que se possa calcular as combinações possíveis.
Assim, tem-se o vetor auxiliar tendo os valores 
das combinações nas suas posições reais.*/

#include <bits/stdc++.h>
#include <iostream>

#define MAX 30001

using namespace std;

int main(){
     //Vetor contendo moedas possíveis
     int cube[5];
     cube[0] = 1;
     cube[1] = 5;
     cube[2] = 10;
     cube[3] = 25;
     cube[4] = 50;

     //Vetor contendo todas as possibilidades para algum valor
          //Esse valor é digitado pelo usuário e corresponde a posição real do vetor
     long long int combinacoes[MAX] = {};
     combinacoes[0] = 1;
     //Primeiro for: percorre cada moeda
     for(int i=0; i<5; i++){
          //Segundo for: percorre o vetor de combinações colocando as combinações possíveis
          for(int j=cube[i]; j<MAX; j++){
               combinacoes[j] += combinacoes[j - cube[i]];
          }
     }
     
     int valor;
     while(scanf("%d", &valor) != EOF){
          if(combinacoes[valor] == 1){
               printf("There is only 1 way to produce %d cents change.\n", valor);
          }
          else{
               printf("There are %lld ways to produce %d cents change.\n", combinacoes[valor], valor);
          }
     }
     return 0;
}