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
    
    int n, k;
    cin >> n >> k;

    int sum = 0;
    for(int i = 0; i < k; i++){
        int k;
        cin >> k;

        sum += k;
    }

    //Mínimo
    float minAvg = sum;
    for(int i = k; i < n; i++){
        minAvg += (-3);
    }
    minAvg /= n;

    //Máximo
    float maxAvg = sum;
    for(int i = k; i < n; i++){
        maxAvg += (3);
    }
    maxAvg /= n;

    cout << minAvg << " " << maxAvg;
    
    return 0;
}