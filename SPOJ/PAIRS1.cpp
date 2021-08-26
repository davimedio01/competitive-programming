#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX 100001

int main(){

    vector<int> total = {};
    int n, k, aux;

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> aux;
        total.push_back(aux);
    }
    sort(total.begin(), total.end());

    long long cont = 0;
    for(int i=0; i<total.size(); i++){ 
        //Procura no vetor as ocorrências para vet[i]+k e retorna o valor (se existir)
        if(binary_search(total.begin(), total.end(), k+total[i]) == true)
            cont++;
    }

    cout << cont << endl;
    
    return 0;
}