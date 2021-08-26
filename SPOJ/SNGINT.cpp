/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long int armazenaDigitos(long int num){

     //Pilha para armazenar dígitos (decrescente)
     stack<int> digitos;

     for(int i=9; i>=2 && num > 1; i--){
          //Enquanto o resto da dívisão número for igual a 0, armazena o dígito no vector
          while(num % i == 0){
               digitos.push(i);
               num /= i;
          }
     }

     //Caso o (Número) não tenha sido dividido até o máx, então é impossível
     if(num != 1)
          return -1;

     //Concatenando dígitos
     long long int digito_final = 0;
     while(!digitos.empty()){
          digito_final = digito_final*10 + digitos.top();
          digitos.pop();
     }
     return digito_final;
}

int main(){

     //Casos de Teste
     int testes;
     cin >> testes;
     while(testes--){

          //Número N
          long int numero;
          cin >> numero;

          //Verificando se o número digitado está entre 0 e 9
          if(numero <= 9){
               //Como "M" > 0, então
               if(numero == 0){
                    cout << "10" << endl;
               }
               else{
                    cout << numero << endl;
               }
          }
          else{
               //Se for maior que 9, realizar operações e printar dígito
               cout << armazenaDigitos(numero) << endl;
          }

     }
     
     return 0;
}