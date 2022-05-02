/*
Author: Davi Augusto Neves Leite
Date: 14/09/2020

Explicação

Seja:

X = quantidade de vezes que pega 2 de A e 1 de B;
Y = quantidade de vezes que pega 2 de B e 1 de A;

Tem-se que:

A = 2X + Y;
B = X + 2Y;

A partir disso, resolvendo o sistema acima (método de Gauss):

3X = 2A - B
3Y = 2B - A
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

    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;

        if ((2 * a - b) >= 0 && (2 * a - b) % 3 == 0 &&
            (2 * b - a) >= 0 && (2 * b - a) % 3 == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}