/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício consiste em, dado 5 valores entre
1 a 50, determinar se o resultado 
(utilizando-se de três operadores matemáticas)
pode ser 23.

Uso de backtracking:

1° - Escolhas: cinco valores entre 1 a 50 e utilização
               dos operadores {+,-,*}
2° - Restrições: o resultado precisa ser 23 e diferente de negativo
3° - Objetivo: verificar se é possível ou não o resultado ser 23
               a partir do conjunto de cinco valores

Ou seja: uma função que pega a primeira posição e testa todas as operações
com os próximos números e suas respectivas posições. Caso retorne falso,
permutar a posição atual com a próxima (ordem dos fatores e operações)
até encerrar. Essa permutação é possível pois o exercício simplismente
pede para verificar e existência de "uma expressão matemática" que de 
como resposta 23 com base no conjunto de dados.
*/
#include <bits/stdc++.h>
#include <iostream>

#define MAX 5
#define MAXVALOR 23
#define SOMA +
#define SUBTRAI -
#define MULTIPLICA *

using namespace std;

//Uso de Backtracking
bool verifica23(int vetor[], int result_atual, int pos_atual)
{
     //Restrição 1: Se a posição atual chegar no final, não pode avançar
     //Restrição 2: Precisa verificar se o result_atual vale 23 (se sim, true)
     if (pos_atual == MAX)
     {
          return (result_atual == MAXVALOR);
     }

     //Salvando o valor numa auxiliar (para operar com a result_atual)
     int aux = vetor[pos_atual];

     //Realizar TODAS as operações possíveis e ver se alguma vai dar certo...
     return (verifica23(vetor, result_atual + aux, pos_atual + 1) ||
             verifica23(vetor, result_atual - aux, pos_atual + 1) ||
             verifica23(vetor, result_atual * aux, pos_atual + 1));
}


//Ler todos os valores
bool leValores(int *vetor){
     for(int i=0; i<MAX; i++){
          cin >> vetor[i];
     }
     return true;
}

//Verificar se todos dígitos são 0
bool verificaZeros(int vetor[]){
     for(int i=0; i<MAX; i++){
          if(vetor[i] != 0)
               return false;
     }
     return true;
}

int main(){

     //Vetor contendo os valores
     int valores[MAX];
     
     while(leValores(valores) && !verificaZeros(valores))
     {
          //Auxiliar contendo resposta final
          bool resp_final = false;
          //Ordenando o vetor para operações e permutações (por conta da função de permutação)
          sort(valores, valores+MAX);

          do //Permutando sempre que necessário
          {    
               resp_final = verifica23(valores, valores[0], 1); //Restrição da Multiplicação (não pode dar 0)
               //Caso verdadeiro, ótimo: resposta encontrada
               if(resp_final == true)
                    break;
               //Do contrário, permutar uma posição do vetor e realizar operações novamente
          }while(next_permutation(valores, valores+MAX));

          //Printando
          if(resp_final == true)
               cout << "Possible" << endl;
          else
               cout << "Impossible" << endl;
     }

     return 0;
}