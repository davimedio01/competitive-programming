/*
Author: Davi Augusto Neves Leite
Date: 27/08/2021

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
    cout.tie(0);
    
    int N;
    cin >> N;

    while(N--){

        int B;
        float P;

        cin >> B >> P;

        float BPM = 60.0 * (B / P);
        float diff = (60.0 / P);    //Encontrando Delta
        float minABPM = (BPM - diff);
        float maxABPM = (BPM + diff);

        printf("%.4f %.4f %.4f\n", minABPM, BPM, maxABPM);
    }
    
    return 0;
}