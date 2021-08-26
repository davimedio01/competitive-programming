/*
Author: Davi Augusto Neves Leite
Date: 17/09/2020
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

    int n;
    cin >> n;

    //Cada gondola: 1 ou 2 crianças, com total do peso não ultrapassando x
    ll weightGondola;
    cin >> weightGondola;

    vector<ll> weightChild;
    for (int i = 0; i < n; i++) {
        ll child;
        cin >> child;

        weightChild.push_back(child);
    }
    sort(weightChild.begin(), weightChild.end());

    //"Busca Binária"
    ll answer = 0LL;

    ll inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        if (weightChild[inicio] + weightChild[fim] <= weightGondola) {
            inicio++;
            fim--;
        }
        else {
            if (weightChild[inicio] > weightChild[fim]) {
                inicio++;
            }
            else {
                fim--;
            }
        }

        answer++;
    }

    cout << answer << endl;

    return 0;
}