/*
Author: Davi Augusto Neves Leite
Date: 09/09/2020
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    string dnaSequence;
    cin >> dnaSequence;

    long answer = LONG_MIN, aux = 1;
    
    //Percorrer a string e separar os caracteres
    for(long i = 0; i < dnaSequence.size(); i++){
        if(answer < aux){
            answer = aux;
        }
        
        (dnaSequence[i] == dnaSequence[i + 1]) ? aux++ : aux = 1;
    }
    
    cout << answer << endl;

    return 0;
}