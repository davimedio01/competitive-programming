/*
Author: Davi Augusto Neves Leite
Date: 27/08/2021

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
    
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        map<string, bool> city;
        int answer = 0;

        for(int i = 0; i < N; i++){
            string word;
            cin >> word;

            if(city.count(word) == false){
                city.insert(make_pair(word, true));
                answer++;
            }
        }

        cout << answer << endl;
    }
    
    return 0;
}