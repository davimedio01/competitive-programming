/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício é o clássico problema da mochila:
dado o valor máximo que cabe numa mochila,
quais items (com seu peso) podem ser colocados
de forma a ocupar o maior espaço possível?

Uma matriz é utilizada para calculo das possibilidades

*/
#include <bits/stdc++.h>
#include <iostream>

#define MAX 2005

using namespace std;

//Algoritmo do Problema da Mochila
int Knapsack(vector<int> peso, vector<int> valor, int qtd_itens, int capacidade)
{
    //Matriz Auxiliar para Cálculo das Combinações (Vector com tamanho definido)
    vector<vector<int>> combinacoes(qtd_itens+1, vector<int>(capacidade+1, 0));
    
    //Montando a matriz de combinação (linhas = itens/colunas = capacidades)
    for(int linha = 0; linha <= qtd_itens; linha++){
         for(int coluna = 0; coluna <= capacidade; coluna++){
               //Se for o primeiro elemento, basta acrescentar 0 (sem peso/item), valores iniciais para 1ºlinha/coluna
               if(linha == 0 || coluna == 0)
                    combinacoes[linha][coluna] = 0;
               else if(peso[linha-1] <= coluna){
                    //Caso o valor do peso seja menor que o da capacidade...
                         //A combinação será o maior valor entre a combinacao[linha][linha - peso[linha-1]] e a combinacao[linha-1]
                    combinacoes[linha][coluna] = max(combinacoes[linha - 1][coluna], valor[linha - 1] + combinacoes[linha - 1][coluna - peso[linha - 1]]);
               }
               else{
                    //Se o valor do peso for maior que o da capacidade, atribuir o valor anterior
                    combinacoes[linha][coluna] = combinacoes[linha-1][coluna];
               }
         }
    }
    //Ao final do processo, o último valor da matriz será o maior e melhor para o problema
    return combinacoes[qtd_itens][capacidade];
}

int main(){

     int capacidade, qtd_itens;
     cin >> capacidade >> qtd_itens;

     //Vectores: O Peso e Valor de Cada Item.
     vector<int> peso, valor;
     peso.clear(); valor.clear();

     //Atribuindo Peso e Item
     int peso_aux, valor_aux;
     for(int i=0; i<qtd_itens; i++){
          cin >> peso_aux >> valor_aux;
          peso.push_back(peso_aux);
          valor.push_back(valor_aux);
     }

     //Calculando e mostrando resultado final
     cout << Knapsack(peso, valor, qtd_itens, capacidade);

     return 0;
}

