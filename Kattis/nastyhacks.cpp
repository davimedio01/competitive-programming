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

    while(N--){

        ll R, E, C;
        cin >> R >> E >> C;

        ll totalAd = E - C;

        if(R < totalAd){
            cout << "advertise" << endl;
        }
        else if(R == totalAd){
            cout << "does not matter" << endl;
        }
        else{
            cout << "do not advertise" << endl;
        }

    }
    
    return 0;
}