/*
Author: Davi Augusto Neves Leite
Date: 13/09/2020
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

    long n;
    cin >> n;

    ll answer = 1;
    for(long i = 0; i < n; i++){
        answer = (answer * 2) % MODULO;
    }

    cout << answer << endl;
    
    return 0;
}