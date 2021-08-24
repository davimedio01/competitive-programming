/*
Author: Davi Augusto Neves Leite
Date: 28/06/2021

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

    int n;
    cin >> n;

    int chest, biceps, back;
    chest = biceps = back;

    for(int i = 1; i <= n; i++){
        int repeat;
        cin >> repeat;

        if(i % 3 == 1){
            chest += repeat;
        }
        else if(i % 3 == 2){
            biceps += repeat;
        }
        else{
            back += repeat;
        }
    }

    int answer = max(max(chest, biceps), back);

    if(answer == chest){
        cout << "chest" << endl;
    }
    else if(answer == biceps){
        cout << "biceps" << endl;
    }
    else{
        cout << "back" << endl;
    }

    return 0;
}