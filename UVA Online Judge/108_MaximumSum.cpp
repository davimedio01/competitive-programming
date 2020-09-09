/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício consiste em encontrar a soma máxima
de um sub-retângulo de uma matriz quadrada dada.

Para resolver o problema, é necessário
aplicar o Algoritmo de Kadane, utilizado para
o cálculo da "Soma Máxima de Um Sub-Retângulo
de um Vetor", para a matriz digitada.
Ou seja, utilizar esse algoritmo diversas vezes
conforme a ordem da matriz.

Inicialmente, são necessárias duas variáveis para 
marcar as colunas "esquerda e direita" que serão
fixas, para encontrar a soma máxima de linhas contínuas para cada
par das colunas "esquerda"/"direita".
Ou seja: encontra-se o número das linhas superior/inferior que possuem
soma máxima para CADA par de colunas esquerda/direita.

Para encontrar essas linhas superior/inferior, é necessário o cálculo
da soma dos elementos de todas as linhas da "esquerda"/"direita",
armazenando cada soma no vetor "aux".

Então, esse aux[i] indica a soma dos elementos da esquerda/direita
na LINHA I. Aplica-se o Algoritmo de Kadane para encontrar a soma
máxima desse sub-array "aux" (soma máxima possível com as colunas
fixas "esquerda"/"direita"). Por fim, a variável "soma_global" irá
receber esse valor, caso seja maior, da aplicação de Kadane.
Sendo assim, repete-se o processo até encontrar 
a soma máxima global (de fato).
*/
#include <bits/stdc++.h>
#include <iostream>

#define MAX 101

using namespace std;

//Algoritmo de Kadane: Soma sub-retângulo
int Kadane(int *vet, int *inicio, int *fim, int tam_matriz){
     int soma_local = 0; //Variável contendo a soma local (cada iteração)
     int soma_global = 0; //Variável contendo a soma global (ou final da iteração)

     (*fim) = -1; //Checar todos valores negativos
     int inicio_local = 0; //Auxiliar marcando a posição de início local para matriz

     for(int i=0; i<tam_matriz; i++){
          soma_local += vet[i];
          //Caso a soma dê negativo (indicando que é o menor possível)
          if(soma_local < 0){
               soma_local = 0;
               inicio_local = i+1;
          }
          else if(soma_local > soma_global){
               soma_global = soma_local;
               //Marcar o início e fim da soma local
               (*inicio) = inicio_local;
               (*fim) = i;
          }
     }
     //Se tem pelo menos um valor não negativo
     if((*fim) != -1)
          return soma_global;
     
     //Se todos os números forem negativos
     soma_global = vet[0];
     (*inicio) = (*fim) = 0;
     for(int i=1; i<tam_matriz; i++){
          if(vet[i] > soma_global){
               soma_global = vet[i];
               (*inicio) = (*fim) = i;
          }
     }

     return soma_global;
}

//Função Principal para Cálculo da Soma Máx
int somaMaxMatriz(int matriz[][MAX], int tam_mat){
     //Variável contendo a soma global (soma máxima de parte da matriz)
     int soma_global = 0;
     //Variáveis para marcar as colunas "esquerda"/"direita"
     int esquerda, direita;
     //Auxiliar contendo a soma máxima de cada coluna
     int aux[MAX] = {};
     //Outras auxiliares: marcar o resultado do Kadane
     int soma_kadane, inicio, fim;

     //Fixando a coluna da esquerda
     for(esquerda = 0; esquerda < tam_mat; esquerda++){
          //Iniciando a auxiliar com 0
          memset(aux, 0, sizeof(aux));

          //Fixando a coluna da direita com a da esquerda (percorrer cada coluna)
          for(direita = esquerda; direita < tam_mat; direita++){

               //Definindo a soma de um retângulo para linhas i
               for(int i=0; i<tam_mat; i++){
                    aux[i] += matriz[i][direita];
               }

               //Encontrando a soma máxima do retângulo anterior
               soma_kadane = Kadane(aux, &inicio, &fim, tam_mat);

               //Comparando com soma global
               if(soma_kadane > soma_global){
                    soma_global = soma_kadane;
               }
          }
     }

     return soma_global;
}

int main(){

     //Tamanho da matriz
     int tam_mat;
     cin >> tam_mat;
     //Declaração da matriz
     int matriz[MAX][MAX] = {};
     //Lendo e anotando valores na matriz
     for(int i=0; i<tam_mat; i++){
          for(int j=0; j<tam_mat; j++){
               cin >> matriz[i][j];
          }
     }
     
     cout << somaMaxMatriz(matriz, tam_mat) << endl;
     
     return 0;
}