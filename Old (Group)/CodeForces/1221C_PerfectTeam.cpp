/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     int casos;
     cin >> casos;
     while(casos--)
     {
          //Coders, Mathematicans e No Specialization
          long long int coders, math, no_spe;
          cin >> coders >> math >> no_spe;

          //Soma de times
          long long int time = 0;

          //Distância entre os Coders/Math
          long long int distancia = max(coders, math) - min(coders, math);

          //Verificando e tirando distâncias
          if(coders > math)
               coders -= distancia;
          if(coders < math)
               math -= distancia;
          
          //Acrescentando nos Não_Especializados
          no_spe += distancia;

          //Pegando o mínimo entre os três
          time = min(min(coders, math), no_spe);

          //Retirando o mínimo de Coders/Math
          coders -= time;
          math -= time;

          //Se sobrou
          if(coders != 0 && math != 0)
               time += (coders + math)/3;

          cout << time << endl;
     }
     
     return 0;
}

/*if(no_spe != 0)
          {
               while (no_spe > 0)
               {
                    if (coders != 0 && math != 0)
                    {
                         no_spe--;
                         coders--;
                         math--;
                         time++;
                    }
                    else
                    {
                         break;
                    }
               }
               //Se sobrou
               if (coders != 0 && math != 0)
               {
                    if(coders == math)
                    {
                         time += (coders + math) / 3;
                    }
                    else
                    {
                         time += min(coders, math);
                    }
                    
               }
          }
          else
          {
               
          }*/