/*
Author: Davi Augusto Neves Leite
Date: 27/08/2021

Compilar com os argumentos: -O2 -Wall -Wextra
Executar com os argumentos: < input.txt > output.txt

https://open.kattis.com/problems/weakvertices
*/

#include <bits/stdc++.h>

#define MAX_MATRIX 20
#define MODULO 1000000007

typedef long long ll;

using namespace std;




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;

    while((cin >> N) && N != -1){

        //Matriz de Adjacência
        int adjMatrix[MAX_MATRIX][MAX_MATRIX];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int element;
                cin >> element;

                adjMatrix[i][j] = element;
            }
        }
        


    }

    return 0;
}