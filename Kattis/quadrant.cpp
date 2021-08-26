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
    
    int x, y;
    cin >> x >> y;

    //Primeiro Quadrante
    if(x > 0 && y > 0){
        cout << "1";
    }
    //Segundo Quadrante
    else if(x < 0 && y > 0){
        cout << "2";
    }
    //Terceiro Quadrante
    else if (x < 0 && y < 0){
        cout << "3";
    }
    //Quarto Quadrante
    else if (x > 0 && y < 0){
        cout << "4";
    }

    return 0;
}