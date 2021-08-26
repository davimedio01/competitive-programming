/*
Author: Davi Augusto Neves Leite
Date: 29/06/2021

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

    string stone;
    cin >> stone;

    string instruction;
    cin >> instruction;

    int totalMoves = 1;
    for(int i = 0; i < instruction.length(); i++){
        if(stone[totalMoves - 1] == instruction[i]){
            totalMoves++;
        }

    }

    cout << totalMoves << endl;
    
    
    return 0;
}