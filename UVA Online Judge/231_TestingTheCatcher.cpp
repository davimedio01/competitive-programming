/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício consiste em contar as interceptações
máximas de um míssil defensivo.

Para intercepctar, exigem-se duas condições:

1) ser o primeiro da sequência
OU
2) ser disparado após o último míssil interceptado e não ser maior que o último interceptado

Com isso, utiliza-se o problema da
"Máxima Subsequência Crescente" (LIS)
de uma maneira decrescente (Máxima Subsequência Decrescente - LDS).

O LIS, em programação competitiva,
exige-se dois vetores:
um com todos os valores na ordem que foram digitados;
o outro sendo um contador de maiores subsequências quebradas

Por exemplo: 
     Vetor = {9,5,6,3,9,6,4,7}
     Sequências decrescentes: {(9,6,4), (5,3), (7), (9,6,4)} = 3 (maior quantidade em um conjunto)

No exemplo acima, o segundo vetor está mostrando as sequências. Mas,
de fato, ficará o valor final do tamanho dessa sequência.
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     int missel = 0, caso_teste = 1;

     //Declarando Vector para Sequência de Número
     vector<int> seq_numeros;
     //ProgComp: Vector contendo comprimento máximo da LIS
     vector<int> compmax_LIS;

     while (cin >> missel && missel != -1){
          //Printar linha vazia pra Caso de Teste > 1
          if (caso_teste != 1)
               cout << endl;
          /*cin >> missel;
          if (missel == -1)
               break;*/
          
          //Zerando Vector para Sequência de Número
          seq_numeros.clear();
          //Armazenando primeiro número da sequência
          seq_numeros.push_back(missel);

          while (cin >> missel && missel != -1){
               /*cin >> missel;
               if (missel == -1)
                    break;*/
               //Armazenando outros números até digitar -1
               seq_numeros.push_back(missel);
          }
          //ProgComp: Vector contendo comprimento máximo da LIS
          compmax_LIS.clear();
          compmax_LIS.push_back(1); //sempre primeiro número conta

          //Contador final
          int cont_final = 1; //1: sempre primeiro número conta
          
          //Verificando números (LIS decrescente)
          for(int i=1; i<seq_numeros.size(); i++){
               compmax_LIS.push_back(1);
               for(int j = 0; j < i; j++){
                    //LIS - Decrescente
                         //Verificando números e o comprimento máximo (de sequência)
                    if(seq_numeros[j] > seq_numeros[i] && compmax_LIS[j]+1 > compmax_LIS[i]){
                         compmax_LIS[i] = compmax_LIS[j]+1;
                         //Pegar o valor máximo do comprimento máximo
                         if(cont_final < compmax_LIS[i]){
                              cont_final = compmax_LIS[i];
                         }

                    }
               }
          }
          
          //Saída
          cout << "Test #" << caso_teste << ':' << endl;
          cout << "  maximum possible interceptions: " << cont_final << endl;
          caso_teste++;
          missel = 0;
     }

     return 0;
}
