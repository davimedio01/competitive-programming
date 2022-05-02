/*
Author: Davi Augusto Neves Leite
Date: 15/09/2020
*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    string digits;
    cin >> digits;

    sort(digits.begin(), digits.end());

    //Vetor contendo todas as possibilidades e contador final
    vector<string> possibilities;
    ll countPossibilities = 0;

    //Todas as possibilidades
    do{
        possibilities.push_back(digits);
        countPossibilities++;
    }while(next_permutation(digits.begin(), digits.end()));
    
    cout << countPossibilities << endl;
    for(ll i = 0; i < possibilities.size(); i++){
        cout << possibilities[i] << endl;
    }


    return 0;
}