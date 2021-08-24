/*
Author: Davi Augusto Neves Leite
Date: 27/06/2021

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
    
    int n;
    cin >> n;

    //N is odd: no perfect permutation
    if(n % 2 != 0){
        cout << "-1" << endl;
    }
    else{
        vector<int> numbers (n + 1);
        iota(numbers.begin(), numbers.end(), 0);

        for(int i = 1; i <= n; i += 2){
            swap(numbers[i], numbers[i + 1]);
        }

        cout << numbers[1];
        for (int i = 2; i <= n; i++){
            cout << " " << numbers[i];
        }
        cout << endl;
    }
    
    return 0;
}