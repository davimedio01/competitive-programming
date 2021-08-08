/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
*/

#include <bits/stdc++.h>
#include <iostream>

#define MAX 100010

using namespace std;

bool comp1(pair<long, long> &i, pair<long, long> &j){
     return (i.first < j.first);
}

int main(){

     int qtd;
     cin >> qtd;
     
     //Vector com Pair
     vector<pair<long int, long int>> marmota;
     marmota.clear();
     pair<long int, long int> conj;
     for(int i=0; i<qtd; i++)
     {
          cin >> conj.first;
          conj.second = i;
          marmota.push_back(conj);
     }

     //Ordenando por número
     sort(marmota.begin(), marmota.end());
 
     //Vetor auxiliar contendo a tristeza
     int tristeza[MAX];
     
     //Analisando
     long int aux = 0; //Índice auxiliar
     for(int i=0; i<qtd; i++)
     {
          /*
          O "aux" marca a posição original do menor elemento. (início em 0)
          Com isso, basta verificar a diferença dessa posição com a posição original.
          Caso de negativo, pegar o valor 0.

          Sendo assim, "aux" irá receber a maior posição entre ela e o do vetor original.

          -> Basta adicionar a diferença citada acima no vetor "tristeza" (resultado final)
          OBS: como o primeiro elemento no vetor ordenado é o menor na sequência,
          basta verificar a distância da posição original dele com a posição do elemento
          atual analisado (i)
          */
          tristeza[marmota[i].second] = max((long int) 0, aux - marmota[i].second);
          aux = max(aux, marmota[i].second);
     }

     //Printando (valor_atual - 1)
     for (int i = 0; i < qtd; i++)
     {
          cout << tristeza[i] - 1 << " ";
     }
     cout << endl;

     return 0;
}
/*
//print j-i - 1
     //AUXILIAR*** (CONDIÇÕES)
     -> aux = 0 (primeira posição)

//0 - 4 = -4 -> 0
     -> aux = 4 (maior posição entre ela e o vet[i])
//4 - 3 = 1  -> 0
     -> aux = 4 (maior posição entre ela e o vet[i])
//4 - 1 = 3  -> 2
     -> aux = 4
//4 - 2 = 2  -> 1
     -> aux = 4
//4 - 5 = -1 (Negativo, resultado vai pra 0) -> -1 
     -> aux = 5
//5 - 0 = 5 -> 4
     -> aux = 5
//5 - 6 = -1 (Negativo, resultado vai pra 0) -> -1
     -> aux = 6

*/