/*
Author: Davi Augusto Neves Leite
Date: 15/09/2020
*/

#include <bits/stdc++.h>

#define MAX 1000002
#define MODULO 1000000007

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    string palindrome;
    getline(cin, palindrome);

    //Percorrendo a string e separando em um map
    map<char, ll> countDigits;
    for(ll i = 0; i < palindrome.size(); i++){
        countDigits[palindrome[i]]++;
    }

    //Salvando a ocorrência de ímpares e o respectivo dígito (usado depois)
    ll oddCount = 0;
    char oddDigit = '0';

    for(auto i = countDigits.begin(); i != countDigits.end(); i++){
        if(i->second % 2 != 0){
            oddCount++;
            oddDigit = i->first;
        }
    }

    //Não é palíndromo quando: mais de uma letra com qtd ímpar; ou um ímpar e total de dígitos da string sendo par
    if(oddCount == 1 && palindrome.size() % 2 == 0 || oddCount > 1){
        cout << "NO SOLUTION" << endl;
    }
    else{
        //Percorrer o Map e salvando os dígitos com ordem de ocorrência
        string firstPart = "";
        for(auto i = countDigits.begin(); i != countDigits.end(); i++){
            for(ll j = 1; j <= i->second/2; j++){
                firstPart += (i->first);
            }
        }

        //Primeira parte do palíndromo
        if(oddDigit != '0'){
            cout << firstPart + oddDigit;
        }
        else{
            cout << firstPart;
        }

        //Segunda parte do palíndromo (primeira parte invertida)
        reverse(firstPart.begin(), firstPart.end());

        cout << firstPart << endl;
    }

    return 0;
}