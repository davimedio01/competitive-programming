/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O exercício consiste em, dado número de linhas
(pode se interpretar como retas), encontrar
o maior número de pedaços (áreas) disponíveis
pelo cruzamento entre as retas

Solução encontrada utilizando a Fórmula de Retas em Posição
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     long int linhas;
     do{
          cin >> linhas;
          if (linhas < 0)
               break;
          
          long int pedacos = 0;
          //Fórmula de "Retas em Posição Geral"
          pedacos = (linhas*linhas + linhas + 2)/2;
          cout << pedacos << endl;
     } while (linhas >= 0);

     return 0;
}