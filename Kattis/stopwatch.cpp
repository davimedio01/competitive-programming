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

    //Se for ímpar, estará sempre rodando
    if(N % 2 != 0){
        cout << "still running";
    }
    //Se for par, estará parado em um número
    else{
        int answer = 0, prev;
        for(int i = 1; i <= N; i++){
            int t;
            cin >> t;
            
            //Iterações ímpares: aumentar o relógio (salvar preverior)
            if(i % 2 != 0){
                prev = t;
            }
            //Iterações pares: pausar o relógio
            else{
                answer += (t - prev);
            }
        }
        cout << answer;
    }
    
    return 0;
}