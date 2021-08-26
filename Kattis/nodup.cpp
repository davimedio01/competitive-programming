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
    
    //Basta utilizar um map em que as chaves simbolizam as palavras.
        //Se já existir, então retorna
    map<string, bool> words;
    string phrase;
    bool answer = true;
    
    while(cin >> phrase){
        if(words.count(phrase) == false){
            words.insert(make_pair(phrase, true));
        }
        else{
            answer = false;
            break;
        }
    }

    (answer) ? cout << "yes" : cout << "no";
    
    return 0;
}