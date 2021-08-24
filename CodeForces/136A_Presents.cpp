/*
Author: Davi Augusto Neves Leite
Date: 27/06/2021

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

    vector<int> friends(n, 0);
    for(int i = 0; i < n; i++){
        int gift;
        cin >> gift;

        friends[gift - 1] = i + 1;
    }

    cout << friends[0];
    for(int i = 1; i < n; i++){
        cout << " " << friends[i];
    }
    cout << endl;
    
    return 0;
}