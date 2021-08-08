/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
Dado tamanho de cada string, junto com o peso
para cada letra do alfabeto,
encontrar o maior valor da subsequência.
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX_LENGTH 2000

//LCS com Pesos
int SubComumMaisCara(string palavra1, int tam_p1,
                     string palavra2, int tam_p2,
                     map<char, int> peso_alfabeto)
{
     //Tabela DP
     vector<vector<int>> dp(tam_p1 + 1, vector<int>(tam_p2 + 1, 0));

     //Percorrendo e verificando
     for (int i = 0; i <= tam_p1; i++)
     {
          for (int j = 0; j <= tam_p2; j++)
          {
               //Se for 1° Linha/Coluna: Zerar
               if (i == 0 || j == 0)
               {
                    dp[i][j] = 0;
               }
               //Caso os char sejam iguais, atribuir na "dp" (com peso)
               else if (palavra1[i - 1] == palavra2[j - 1])
               {
                    dp[i][j] = dp[i - 1][j - 1] + peso_alfabeto[palavra1[i - 1]];
               }
               //Se forem diferentes, pegar o máximo entre a linha anterior e a coluna anterior
               else
               {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
               }
               //cout << dp[i][j] << " ";
          }
          //cout << endl;
     }

     return dp[tam_p1][tam_p2];
}

int main()
{

     //Tamanho das Strings
     int tam1, tam2;
     cin >> tam1 >> tam2;

     //Salvando os pesos das letras do alfabeto
     char letra = 'a';             //letra inicial
     map<char, int> peso_alfabeto; //map contendo pesos
     int peso;                     //auxiliar peso

     for (int i = 1; i <= 26; i++)
     {
          cin >> peso;
          peso_alfabeto.insert(make_pair(letra, peso));
          letra++;
     }

     //Strings para LCS (Longest Common Subsequence)
     string palavra1, palavra2;
     cin >> palavra1 >> palavra2;

     cout << SubComumMaisCara(palavra1, tam1, palavra2, tam2, peso_alfabeto) << endl;

     return 0;
}