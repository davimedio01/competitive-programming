/*
Author: Davi Augusto Neves Leite
Date: 09/09/2020
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    ll n;
    cin >> n;

    while(true){
        cout << n << " ";

        if(n == 1)
            break;
        
        (n % 2 == 0) ? (n /= 2) : (n = (n * 3) + 1);
    }
    
    return 0;
}