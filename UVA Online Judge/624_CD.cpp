/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício consiste em, dado um número de faixas,
suas durações e o número máximo permitido, encotrar
a soma mais próxima do número máximo permitido
(com base nas durações das músicas)

Utilização de Backtracking:

1°: Escolhas -> somar posição a posição, salvar o elemento que somou
2°: Restrições -> soma não pode ser maior que o número dado pelo usuário
3°: Objetivo -> somar até terminar o vetor ou encontrar a soma do valor exato dado pelo usuário

Ou seja:
A função deve, recursivamente, somar os elementos de um vetor
até o resultado ser igual ou o mais próximo possível do valor
dado pelo usuário. Além disso, deve-se utilizar um vetor auxiliar
para salvar os valores utilizados pela soma.
*/

#include <bits/stdc++.h>
#include <iostream>
#define MAX 22
using namespace std;

//Uso de Backtracking
void encontraSoma(vector<int> duracao, vector<int> temp, vector<int> *duracao_final,
                  int soma_atual, int *soma_final, int num_max, int posicao_atual)
{    
     //Primeiramente, somar a posição atual
     soma_atual += duracao[posicao_atual];
     //Armazenar o valor no temp
     temp.push_back(duracao[posicao_atual]);

     //Restrição 1: a soma_atual precisa ser maior do que a soma_final (mais próximo possível) OU
     //Restrição 2: caso sejam iguais, o tamanho do vetor temporario precisa ser maior do que o duracao_final
                    //para se ter a maior quantidade de faixas possível
     if (soma_atual > (*soma_final) || (soma_atual == (*soma_final) && temp.size() > (*duracao_final).size()))
     {
          (*soma_final) = soma_atual;
          (*duracao_final) = temp;
     }

     //Com isso, basta verificar as possibilidades
          //Ou seja: a partir da posicao_atual + 1 até o fim, verificar se a soma da um valor menor ou igual ao num_max
     for(int i = posicao_atual + 1; i < duracao.size(); i++)
     {
          //Restrição 3: soma_final precisa ser o mais próximo possível do num_max
          if(soma_atual + duracao[i] <= num_max)
          {
               //Caso a soma seja menor ou igual, realizar a recursão da função (para soma_atual e temp)
               encontraSoma(duracao, temp, &(*duracao_final), soma_atual, &(*soma_final), num_max, i);
          }
     }
}

int main(){

     //Número máximo permitido
     int num_max;
     //Total de faixas
     int qtd_faixas;
     while (cin >> num_max >> qtd_faixas)
     {
          //Vector contendo a duração de cada faixa e suas posições
          vector<int> duracao; duracao.clear();

          //Captando valores
          int faixa;
          for(int i=0; i<qtd_faixas; i++){
               cin >> faixa;
               duracao.push_back(faixa);
          }

          //Soma final
          int soma_final = 0;
          //Vector contando as durações utilizadas para a soma final
          vector<int> duracao_final; duracao_final.clear();
          
          //Função principal: a partir do primeiro elemento, ele vai somando e comparando as possibilidades
          for(int i=0; i<qtd_faixas; i++)
          {
               //Vector auxiliar para salvar os números utilizados durante uma possibilidade de soma
               vector<int> aux;
               encontraSoma(duracao, aux, &duracao_final, 0, &soma_final, num_max, i);
               //Economizar tempo
               if(soma_final == num_max)
                    break;
          }

          //Mostrando valores e Soma_final
          for(int i=0; i<duracao_final.size(); i++){
               cout << duracao_final[i] << " ";
          }
          cout << "sum:" << soma_final << endl;

     }
     
     return 0;
}