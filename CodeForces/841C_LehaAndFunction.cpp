/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
 O exercício consiste em colocar a maior soma possível
 para cada posição dos vetores. Para isso,
 é levado em conta a posição ORIGINAL do vetor B.

 Ou seja: primeiramente ordenar decrescente o vetor A,
 crescente o vetor B (tendo as posições ORIGINAIS salvas)

 Re-ordenar o vetor A com base nas posições originais de B
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Comparando posições (pair): 1 - A; 2 - B; 3 - A'
bool comparaPair1(pair<long int, long int> &i, pair<long int, long int> &j)
{
     return i.first > j.first;
}
bool comparaPair2(pair<long int, long int> &i, pair<long int, long int> &j)
{
     //Se os elementos forem iguais, ordena o de posição anterior
     if(i.first == j.first){
          return i.second > j.second;
     }
     return i.first < j.first;
}
bool comparaPair3(pair<long int, long int> &i, pair<long int, long int> &j)
{
     return i.second < j.second;
}

int main(){

     //Tamanho dos Vetores e Auxiliar
     long int tam, num;
     cin >> tam;

     //Vetores A e B contendo posições e Auxiliar (Pair)
     vector<pair<long int, long int>> A, B;
     A.clear();
     B.clear();
     pair<long int, long int> aux;
     //Vetor A
     for (long int i = 0; i < tam; i++)
     {
          cin >> num;
          aux.first = num;
          aux.second = i;
          A.push_back(aux);
     }
     //Vetor B
     for (long int i = 0; i < tam; i++)
     {
          cin >> num;
          aux.first = num;
          aux.second = i;
          B.push_back(aux);
     }
     //Ordenando os Vetores: A - Decrescente/B - Crescente
     sort(A.begin(), A.end(), comparaPair1);
     sort(B.begin(), B.end(), comparaPair2);

     //Verificando e atribuindo as posições 
     for(long int i = 0; i < tam; i++){
          A[i].second = B[i].second;
     }
     //Re-ordenando o vetor A
     sort(A.begin(), A.end(), comparaPair3);

     //Printando
     for(long int i = 0; i < tam; i++){
          cout << A[i].first << " ";
     }
     cout << endl;

     return 0;
}