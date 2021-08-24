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
    
    int n, k;
    cin >> n >> k;

    int answer = 0;

    while(n--){
        string number;
        cin >> number;

        int isLucky = 0;

        for(int i = 0; i < number.length(); i++){
            if (number[i] == '4' || number[i] == '7'){
                isLucky++;
            }
        }
        if(isLucky <= k){
            answer++;
        }
    }
    
    cout << answer << endl;

    return 0;
}