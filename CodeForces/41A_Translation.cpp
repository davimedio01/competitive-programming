/*
Author: Davi Augusto Neves Leite
Date: 24/06/2021

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
    
    string s, t;
    cin >> s >> t;
    
    reverse(t.begin(), t.end());

    (s.compare(t) == 0) ? cout << "YES" : cout << "NO";

    return 0;
}