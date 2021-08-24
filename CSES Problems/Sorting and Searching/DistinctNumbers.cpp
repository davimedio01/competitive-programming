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

    ll n;
    cin >> n;

    vector<ll> numbers;
    for(ll i = 0; i < n; i++){
        ll value;
        cin >> value;

        numbers.push_back(value);
    }

    sort(numbers.begin(), numbers.end());

    ll count = 0;
    for(ll i = 0; i < n; i++){
        if(numbers[i] != numbers[i + 1]){
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}