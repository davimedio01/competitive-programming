/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     //Leitura do número de jogadores e de partidas
     int num_jog, num_part, cont, gol;
     bool verifica_gols;
     while (cin >> num_jog >> num_part){

          //Contador final e booleana auxiliar
          cont = 0;
          verifica_gols = true;

          //Fazendo a leitura de cada gol
          while (num_jog--)
          {
               verifica_gols = true;
               for (int i = 1; i <= num_part; i++)
               {
                    cin >> gol;
                    //Caso não haja gol (0), então não pode contar
                    if (gol == 0)
                    {
                         verifica_gols = false;
                    }
               }
               if (verifica_gols)
               {
                    cont++;
               }
          }

          cout << cont << endl;
     }

     
     return 0;
}