/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício consiste em, dado uma string,
verificar qual o número de inserções mínimas para formar
um palíndromo.

Isso pode ser resolvido "quebrando" a string
em menores (substring's) e verificando o número
mínimo de cada. Pode ser utilizado uma
matriz (semelhante ao algoritmo da mochila) para
armazenar as respostas das substrings. (somando com anterior)
*/
#include <bits/stdc++.h>
#include <iostream>

#define MAX 3001

using namespace std;

int insercaoMinimaPalindromoDP(string texto, int tamanho){
     //Para encontrar a resposta final, quebrar a string em substring's e colocar resultado de cada em uma matriz
          //Para tanto, a matriz será preenchida em cada linha (acrescentando uma coluna)
     //vector<vector<int>> combinacoes(tamanho, vector<int>(tamanho, 0));
     int combinacoes[tamanho][tamanho];
     //Zerando matriz
     memset(combinacoes, 0, sizeof(combinacoes));

     //Aux's: "primeiro" = primeira posição do intervalo; "ultimo" = ultima posição do intervalo
          //Esse intervalo é o de análise das substring's
     int primeiro, ultimo;
     //Por fim, o "intervalo" para análisar os intervalos das substrings's (ex: 1º - (0, 1)/(1, 2)/(2, 3)/(3, 4); 2º - (0, 2)/...)
          //Caso utiliza-se recursivo, alguns intervalos poderiam se repetir (como (1,2), (1,3)), aumentando o tempo
     int intervalo;

     //Primeiro For: Cada Iteração Possível
     for(intervalo = 1; intervalo < tamanho; intervalo++){
          //Segundo For: Combinações (intervalos como (1, 2), (2, 3), (3, 4), ...)
          for(primeiro = 0, ultimo = intervalo; ultimo < tamanho; primeiro++, ultimo++){
               //Exemplo: para string com 5 caracteres
                    //1º Iteração: Intervalos = (0,1), (1,2), (2,3), (3,4)
                    //2º Iteração: Intervalos = (0,2), (1,3), (2,4)
                    //3º Iteração: Intervalos = (0,3), (1,4)
                    //4º Iteração: Intervalos = (0,4)
               if(texto[primeiro] == texto[ultimo]){
                    //Se os char's forem iguais, pula uma linha/coluna (recebe 0 o atual)
                    combinacoes[primeiro][ultimo] = combinacoes[primeiro+1][ultimo-1];
               }
               else{
                    //Caso sejam diferentes, recupera o valor mínimo de inserção (já visto na linha/coluna anterior)
                    combinacoes[primeiro][ultimo] = min(combinacoes[primeiro][ultimo-1], combinacoes[primeiro+1][ultimo]) + 1;
               }
          }
     }
     return combinacoes[0][tamanho-1];
}

int main(){

     //Tamanho texto
     int tamanho;
     cin >> tamanho;
     
     //String
     string texto;
     cin >> texto;

     cout << insercaoMinimaPalindromoDP(texto, tamanho) << endl;


     return 0;
}

/*
Algoritmo recursivo para exercício:
     Ou seja, ele quebra a string até se tornar um conjunto de 2 char's

int insercaoMinima(string str, int primeiro, int ultimo)
{
     if(primeiro > ultimo)
          return -1;
     //Se for um único char (próprio palíndromo)
     if(primeiro == ultimo)
          return 0;
     //Se o primeiro char for igual ao último-1 (ex: "aa" = 0; "ab" = 1)
     if(primeiro == ultimo-1)
          return (str[primeiro] == str[ultimo]);
          
     //Análise dos char (quebrando)
     if (str[primeiro] == str[ultimo])
     {
          return insercaoMinima(str, primeiro + 1, ultimo - 1);
     }
     else
     {
          return min(insercaoMinima(str, primeiro + 1, ultimo),
                     insercaoMinima(str, primeiro, ultimo - 1)) + 1;
     }
}*/
