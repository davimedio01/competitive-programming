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

    string word;
    cin >> word;

    map<char, bool> letter;
    bool answer = true;

    for(int i = 0; i < word.length(); i++){
        if(letter.count(word[i]) == 0){
            letter.insert(make_pair(word[i], true));
        }
        else{
            answer = false;
            break;
        }
    }

    (answer) ? cout << "1" : cout << "0";

    return 0;
}