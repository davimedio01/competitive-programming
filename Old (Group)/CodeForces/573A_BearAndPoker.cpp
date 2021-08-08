/*
Teorema: Todo número inteiro positivo pode ser fatorado e escrito como uma sequência de (2^a) * (3^b) * (5^c)...

Ou seja: basta encontrar o mínimo divisor comum entre todos os valores, e separá-los em potencias de 2 e 3, tentando
encontrá-los novamente a partir do mínimo (e 2 e 3). Caso dê para fazer isso, então "Yes", se não "No".
*/

#include <bits/stdc++.h>
#include <iostream>

#define MAX 1e9 + 5

using namespace std;

vector<unsigned long> bids;

unsigned long gcd(unsigned long x, unsigned long y)
{
     if (y == 0)
     {
          return x;
     }

     return gcd(y, x % y);
}


int main(){

     long int num_jogadores;
     cin >> num_jogadores;

     unsigned long bid;
     for(long i = 0; i < num_jogadores; i++)
     {
          cin >> bid;
          bids.push_back(bid);
     }
     
     //Encontrando GCD
     unsigned long minimo = bids[0];
     for(long i = 1; i < num_jogadores; i++){
          minimo = gcd(minimo, bids[i]);
     }
     //cout << minimo << endl;

     //Separando o mínimo em Sequência de 2-3
     while(minimo % 2 == 0)
     {
          minimo /= 2;
     }
     while(minimo % 3 == 0)
     {
          minimo /= 3;
     }

     unsigned int dois, tres;
     bool verifica = true;
     for(long i = 0; i < num_jogadores && verifica; i++){
          dois = 1;
          tres = 1;

          //Encontrando a Sequência de 2-3 para cada valor
          while(bids[i] % (dois * 2) == 0)
          {
               dois *= 2;
               //cout << dois << " ";
          }
          while(bids[i] % (tres * 3) == 0)
          {
               tres *= 3;
               //cout << tres << " ";
          }

          //Caso seja possível reescrever os números (com base no mínimo)
          if((minimo * dois * tres) != bids[i])
          {
               verifica = false;
          }
     }

     if(verifica)
     {
          cout << "Yes" << endl;
     }
     else
     {
          cout << "No" << endl;
     }
     
     
     return 0;
}