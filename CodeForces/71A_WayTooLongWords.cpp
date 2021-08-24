/*
Author: Davi Augusto Neves Leite
Date: 25/06/2021

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

    //Number Test Case
    int n;
    cin >> n;

    while(n--){

        string word;
        cin >> word;

        int wordSize = word.size();

        if(wordSize > 10){
            char first, last;
            first = word[0];
            last = word[wordSize - 1];

            cout << first << (wordSize-2) << last << endl;
        }
        else{
            cout << word << endl;
        }

    }
    
    
    return 0;
}