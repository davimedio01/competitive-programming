/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/**/

#include <bits/stdc++.h>
#include <iostream>

#define MAX 10002

using namespace std;

int main()
{

    //DP: Armazenando todos os valores em um vetor
    vector<long> dp(MAX, 0);
    //Valores exatos
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    //Percorrer de 4 a N no primeiro for (posições da DP[])
    for (int i = 4; i <= MAX; i++)
    {
        /*Aqui está o segredo

          Para encontrar o número de quadrados, basta pensar o seguinte:
          1) todos podem ser decompostos em soma de 1*1 (ex: 6 = 1*1 + 1*1 + 1*1...)
          2) sabendo disso, basta encontrar o maior quadrado para aquele número e somar com
          o número restante de potência de 1 (ex: 6 = 2*2 + 1*1 + 1*1; pois 2*2 = 4 (6 - 4 = 2 = 1*1 + 1*1))

          Com isso, basta utilizar a DP: o primeiro for irá percorrer cada número de 1 a N (armazenando os valores);
          o segundo irá analisar o valor mínimo entre:
          1) o número atual
          2) o valor de quadrados contidos em N - max_quadrado_para_N (ex acima: 6 tem o max_quadrado = 2, pois 2*2 = 4 e 6-4 = 2)
          */
        dp[i] = i; //Auxiliar
        for (long j = 1; j <= ceil(sqrt(MAX)); j++)
        {
            long aux = j * j;
            //Caso o quadrado ultrapasse o número atual (ex: 2*2 > 3 sendo que o ceil(sqrt(3)) seria 2)
            if (aux > i)
            {
                break;
            }
            else
            {
                dp[i] = min(dp[i], dp[i - aux] + 1);
            }
        }
    }

    //Número de testes de caso
    int casos;
    cin >> casos;

    //Lendo cada caso
    int num;
    while (casos--)
    {
        cin >> num;
        cout << dp[num] << endl;
    }

    return 0;
}