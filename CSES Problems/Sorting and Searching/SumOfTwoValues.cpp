/*
Author: Davi Augusto Neves Leite
Date: 21/09/2020
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

    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> elements;
    for(ll i = 0; i < n; i++){
        ll number;
        cin >> number;

        elements.push_back(make_pair(number, i + 1));
    }
    sort(elements.begin(), elements.end());

    ll startIndex, endIndex;

    startIndex = 0;
    endIndex = n - 1;

    while (startIndex < endIndex){
        ll sum = elements[startIndex].first + elements[endIndex].first;
        
        if(sum == x){
            cout << elements[startIndex].second << " " << elements[endIndex].second << endl;
            return 0;
        }
        else if(sum > x){
            endIndex--;
        }
        else{
            startIndex++;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}