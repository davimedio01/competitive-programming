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
    
    int N; 
    cin >> N;

    ll answer = 0;
    for(int i = 0; i < N; i++){
        int P;
        cin >> P;

        //Dígitos
        int digitsP = (P / 10);

        //Expoente
        int powP = (P % 10);

        answer += pow(digitsP, powP);
    }

    cout << answer;

    return 0;
}