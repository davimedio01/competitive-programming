#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX 1001

int main(){

    int n, aux;
    cin >> n;
    
    long int torre[MAX] = {};
    for(int i=0; i<n; i++){
        cin >> aux;
        torre[aux]++;
    }

    //Função de Elemento Máximo em C++
    int cont_torre = *max_element(torre, torre + MAX);
    int cont_total = 0;
    for(int i=0; i<MAX; i++){
        if(torre[i] != 0)
            cont_total++;
    }

    cout << cont_torre << " " << cont_total << endl;


    return 0;
}