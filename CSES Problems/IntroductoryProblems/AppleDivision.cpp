/*
Author: Davi Augusto Neves Leite
Date: 16/09/2020

Explicação

*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

vector<ll> a, b;
ll answer;

//Retorna a soma total de um vector
ll returnSumVector(vector<ll> a) {
    ll sum = 0LL;
    for (ll i = 0; i < a.size(); i++) {
        sum += a[i];
    }

    return sum;
}

//Encontrar a soma mínima de maneira recursiva, de tal forma que a diferença entre a soma total e a mínima seja a menor possível
void findMin(vector<ll> appleWeight, vector<ll> a, vector<ll> b,
            int position) {
    //Caso chegue ao final do vetor, verificar o mínimo
    if (position == -1) {
        answer = min(answer, llabs(returnSumVector(a) - returnSumVector(b)));
        return;
    }

    //Atribuindo ao primeiro set
    a.push_back(appleWeight[position]);
    findMin(appleWeight, a, b, position - 1);
    a.pop_back();

    //Atribuindo ao segundo set
    b.push_back(appleWeight[position]);
    findMin(appleWeight, a, b, position - 1);
    b.pop_back();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    int n;
    cin >> n;

    //Armazenar os elementos
    vector<ll> appleWeight;
    for (int i = 0; i < n; i++) {
        ll weight;
        cin >> weight;

        appleWeight.push_back(weight);
    }

    answer = LONG_LONG_MAX;

    findMin(appleWeight, a, b, n - 1);

    cout << answer << endl;

    return 0;
}