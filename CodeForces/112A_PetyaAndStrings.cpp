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
                                                                                           
    string firstWord, secondWord;
    cin >> firstWord >> secondWord;

    int sizeWord = firstWord.size();
    int answer;                                                                                  

    for(int i = 0; i < sizeWord; i++){
        if (tolower(firstWord[i]) != tolower(secondWord[i])){
            if (tolower(firstWord[i]) > tolower(secondWord[i])){
                answer = 1;
            }
            else{
                answer = -1;
            }
            break;
        }
        answer = 0;
    }

    cout << answer << endl;
    
    return 0; 
}
