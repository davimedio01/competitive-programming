/*
Author: Davi Augusto Neves Leite
Date: 26/08/2021

Compilar com os argumentos: -O2 -Wall -Wextra
Executar com os argumentos: < input.txt > output.txt
*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N = 1;    
    int numWinner = 0, pointsWinner = -1;

    while(N <= 5){

        int value = 0;
        for(int i = 0; i < 4; i++){
            int aux;
            cin >> aux;

            value += aux;
        }

        if(value > pointsWinner){
            numWinner = N;
            pointsWinner = value;
        }

        N++;
    }

    cout << numWinner << " " << pointsWinner;
    
    return 0;
}