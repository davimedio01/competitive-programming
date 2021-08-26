/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício consiste em, dado um intervalo inclusivo,
mostrar todos os números primos desse intervalo.
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     //Casos Testes
     int testes;
     cin >> testes;
     
     while(testes--){
          //Intervalos: Abertura e Fechamento
          long int abre, fecha;
          cin >> abre >> fecha;

          //Bool auxiliar
          bool verifica;

          //Percorrendo o Intervalo
          for(long int i=abre; i<=fecha; i++){
               //Pulando o número 1
               if(i == 1)
                    i++;
               if(i == 2){
                    printf("%ld\n", i);
               }
               else{
                    verifica = 1;
                    //Números maiores que 3 e ímpares (economia memória)
                    for(long int j = 2; j <= sqrt(i) && verifica; j++){
                         if(i % j == 0){
                              verifica = 0;
                         }
                    }
                    if(verifica == 1)
                         printf("%ld\n", i);
               }
          }
          printf("\n");
     }

     
     return 0;
}