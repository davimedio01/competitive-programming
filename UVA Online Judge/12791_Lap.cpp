/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     //Velocidades: Lider e Ultimo
     int lider, ultimo;
     while(cin >> lider >> ultimo)
     {
          //Contador de voltas
          int voltas = 1;
          //"Faltando" para ultrapassagem de "lider" sobre "ultimo"
          int ultrapassa = 0;

          //Calculando a ultrapassagem: (ultimo - lider) * voltas
          while(ultrapassa < lider)
          {
               ultrapassa = (ultimo - lider) * voltas;
               voltas++;
          }
          cout << voltas << endl;
     }
     
     return 0;
}