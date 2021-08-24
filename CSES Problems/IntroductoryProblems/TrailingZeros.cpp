/*
Author: Davi Augusto Neves Leite
Date: 13/09/2020
*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    ll n;
    cin >> n;

    //Para obter a maior sequência de 0's de uma fatorial, basta contar as divisões por potências de 5 do número
    ll answer = 0;
    for (int i = 5; (n / i) >= 1; i *= 5) {
        answer += (n / i);
    }

    cout << answer;

    return 0;
}