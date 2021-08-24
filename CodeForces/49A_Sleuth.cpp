/*
Author: Davi Augusto Neves Leite
Date: 24/06/2021

Compilar com os argumentos: -O2 -Wall -Wextra
Executar com os argumentos: < input.txt > output.txt
*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

bool isVowel(char letter){
    if (letter == 'A' ||
        letter == 'E' ||
        letter == 'I' ||
        letter == 'O' ||
        letter == 'U' ||
        letter == 'Y')
    {
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char prev, actual;

    while ((actual = getchar()) != '\n'){
        if (actual != ' '){
            if (actual == '?'){
                (isVowel(toupper(prev))) ? cout << "YES\n" : cout << "NO\n";
                return 0;
            }
            prev = actual;
        }
    }

    return 0;
}