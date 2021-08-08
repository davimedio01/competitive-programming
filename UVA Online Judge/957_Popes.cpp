/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     long long anos, qtd_papas;

     while (cin >> anos >> qtd_papas)
     {

          //Vector contendo o número de papas
          vector<long long> papas;
          
          for (long long i = 0; i < qtd_papas; i++)
          {
               long long aux;
               cin >> aux;

               papas.push_back(aux);
          }

          //Variáveis contendo contadores finais
          long long max_final, min_final, papas_final = -1;

          //Analisando resultados
               //Auxiliar contendo o último papa eleito num intervalo
          long long ultimo = 0, aux_soma = 0;
          for(long long i = 0; i < qtd_papas; i++)
          {
               //Auxiliar contendo a soma do papa[i] + anos para análise do último papa eleito
                    //Por exemplo, primeiro valor é 1 e anos é 5, o que totalilza 6
                         //Esse 6 é o primeiro papa eleito (min_final)
                              //E o último (neste intervalo de análise)
               aux_soma = papas[i] + anos;

               //Acrescentar numa auxiliar de posição, a posição do primeiro papa eleito para o número de anos dado
                    //Utilizando o exemplo do exercício, ele irá somar da posição 0 (1) até a posição 3 (6),
                         //haja visto que 6 é o primeiro papa eleito para o valor de anos dado pelo usuário (5).
                         //Também é levado o valor da posição em consideração (ex: a soma dar 7 e o valor do vet[último] ser maior)
               while((ultimo < qtd_papas) && (papas[ultimo] < aux_soma))
                    ultimo++; //Ou seja, só vai somar posição se existir tanto a soma quanto a posição no vetor
               
               //Verificação para armazenar os valores
                    //Caso a posição do último menos a atual seja maior que a qtd de papas
               if(ultimo - i > papas_final)
               {
                    papas_final = ultimo - i;
                    min_final = papas[i];
                    max_final = papas[ultimo - 1];
               }
          }

          cout << papas_final << " " << min_final << " " << max_final << endl;
     }

     return 0;
}