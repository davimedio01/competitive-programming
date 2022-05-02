/*
Author: Davi Augusto Neves Leite
Date: 15/09/2020

Explicação:

Primeiramente, analisar os casos bases:

n = 1 ou n = 2 => impossível => Soma PA (1): 1 / Soma PA (2): 3
n = 3 => A = {1, 2} e B = {3} => Soma PA: 6 (3 em cada)
n = 4 => A = {2, 3} e B = {1, 4} => Soma PA: 10 (5 em cada)
n = 5 ou n = 6 => impossível => Soma PA (5): 15 / Soma PA (6): 21
n = 7 => A = {1, 2, 4, 7} e B = {3, 5, 6} => Soma PA: 28 (14 em cada lado)

Ou seja, percebe-se que será possível quando a Soma PA for par.

A partir disso, basta separar dividindo a Soma PA por dois (cada set) e colocando
os elementos até completar essa soma.

*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    ll n;
    cin >> n;

    //Soma Par: é possível
    if ((n * (1 + n) / 2) % 2 == 0) {
        cout << "YES" << endl;

        //Set's
        vector<ll> A, B;

        //Soma Auxiliar
        ll intervalSets = n * (1 + n) / 4;

        //Realizar looping e separar os números
        while (n > 0)
        {
            //Basicamente, analisando apenas um set até a soma ficar igual a (Soma PA)/2
            if (intervalSets - n >= 0) {
                A.push_back(n);
                intervalSets -= n;
            }
            else {
                B.push_back(n);
            }

            n--;
        }

        //Primeiro Set
        sort(A.begin(), A.end());
        cout << A.size() << endl;
        for (ll i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;

        //Segundo Set
        sort(B.begin(), B.end());
        cout << B.size() << endl;
        for (ll i = 0; i < B.size(); i++) {
            cout << B[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}