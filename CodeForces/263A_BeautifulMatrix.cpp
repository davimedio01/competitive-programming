/*
Author: Davi Augusto Neves Leite
Date: 29/06/2021

Compilar com os argumentos: -O2 -Wall -Wextra
Executar com os argumentos: < input.txt > output.txt
*/

#include <bits/stdc++.h>

#define MODULO 1000000007
#define MAX_MATRIX 5

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> posOne;
    for(int i = 0; i < MAX_MATRIX; i++){
        for (int j = 0; j < MAX_MATRIX; j++){
            int element;
            cin >> element;

            if(element == 1){
                posOne.first = i;
                posOne.second = j;
            }
        }
    }

    //Calculate the differences
    int diffX = abs(2 - posOne.first);
    int diffY = abs(2 - posOne.second);

    //Answer
    cout << (diffX + diffY) << endl;
    
    
    return 0;
}