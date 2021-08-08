/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício consiste em ter a maior soma consecutiva.
Caso a soma seja negativa, voltar para o valor 0 de início.
Caso a soma seja maior que "maior", o "maior" recebe soma.

Usuário digita quantos valores quiser
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Função final de somar consecutivo
int somaConsecutivo(vector<int> valores)
{
     //Variáveis auxiliares para: soma máxima, soma atual
     int soma = 0, max = 0;
     for (int i = 0; i < valores.size(); i++)
     {
          //Somando valores e verificando
          soma += valores[i];
          if (soma < 0)
          {
               soma = 0;
          }
          else if (soma > max)
          {
               max = soma;
          }
     }
     return max;
}

int main(){
     //Vetor contendo valores para soma
     vector<int> valores;  

     string linha;
     while(getline(cin, linha)){
          //Terminando de digitar, recuperar números com "stringstream"
          stringstream temp(linha);
          int numeros;
          valores.clear();
          while(temp >> numeros){
               valores.push_back(numeros);
          }
          cout << somaConsecutivo(valores) << endl;
     }
     
     return 0;
}