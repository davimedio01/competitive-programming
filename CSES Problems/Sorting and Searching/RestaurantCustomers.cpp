/*
Author: Davi Augusto Neves Leite
Date: 18/09/2020
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

    vector<ll> arrival, leaving;
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;

        arrival.push_back(a);
        leaving.push_back(b);
    }
    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());

    ll arrivalCustomer, maxCustomer;

    arrivalCustomer = 0LL;
    maxCustomer = -1;

    ll posIn, posOut;
    
    posIn = 0LL;
    posOut = 0LL;

    while(posIn < arrival.size() && posOut < leaving.size()){

        if(arrival[posIn] <= leaving[posOut]){
            arrivalCustomer++;
            posIn++;

            if(maxCustomer < arrivalCustomer){
                maxCustomer = arrivalCustomer;
            }
        }
        else{
            arrivalCustomer--;
            posOut++;
        }
    }

    cout << maxCustomer << endl;

    return 0;
}