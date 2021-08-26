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

//Encontrar o último dígito de uma fatorial, sem excluir o 0
int lastDigitFactorial(int N){
    if(N == 0)
        return 1;
    else if(N <= 2)
        return N;
    else if(N == 3)
        return 6;
    else if(N == 4)
        return 4;
    else
        return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        /*
            Para descobrir o último dígito de um número, neste caso,
            basta perceber que TODAS as fatorias de 5 para cima (inclusivo)
            tem o último dígito valendo 0...
        */

        cout << lastDigitFactorial(N) << endl;
    }
    
    return 0;
}