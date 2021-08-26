/*
O exercício deseja saber o número de caminhos (com repetição)
para se definir os números da casa de maneira que:

1) Se o pinguim começar de qualquer casa de 1 até K, inclusivo,
ele pode caminhar para a "casa 1".
2) Se o pinguim começar de qualquer casa de K + 1 até N, inclusivo,
ele não pode caminhar para a "casa 1".
3) Se o pinguim começa caminhando da "casa 1", ele somente pode
voltar para ela após a presença de um número não-nulo de caminhada de 
uma casa a outra.

*Dividir resultado por 1000000007 (10^9 + 7)

Além disso: K-max = 8
--------------------------------------------------------------------------------
Ou seja: se considerarmos as repetições, tendo um limite K em que,
desta forma, temos dois intervalos para calcular:

1) 1 até K (pode ser visto por força bruta, em que K^K)
2) K + 1 até N, que pode ser transcrito por N - K (o importante é a quantidade, e não posição)

Além disso, sabemos que em "2)" ele NÃO pode voltar para a "casa 1" e, portanto,
a partir deste ponto temos a seguinte possiblidade:
(n - k)^(n - k).

Portanto: o primeiro passo é encontrar todas as chances dele para caminhar da "casa 1" até K ("com possíveis voltas");
e multiplicar isso pela caminhada com as outras "N-K casas" -> '1)' E '2)'

Resposta final: 1) * 2) => K^K * (N - K)^(N - K)
-----------------------------------------------------------------------------------------------------------------------

*/

#include <bits/stdc++.h>
#include <iostream>

#define MODULO_MAX 1000000007

using namespace std;

long long Resolve(int n, int k)
{
     //Realizando a fórmula: (K^K) * (N - K)^(N - K)
     long long resultado = 1;
     
     //1° passo: (K^K)
     for(long long i = 1; i < k; i++)
     {
          resultado = (resultado * k) % MODULO_MAX;
     }

     //2° passo: (N - K)^(N - K)
     for(long long i = 1; i <= n - k; i++)
     {
          resultado = (resultado * (n - k)) % MODULO_MAX;
     }

     return resultado;
}


int main(){

     int n, k;
     cin >> n >> k;

     //Realizando a fórmula: (K^K) * (N - K)^(N - K)
     cout << Resolve(n, k) << endl;
     
     return 0;
}