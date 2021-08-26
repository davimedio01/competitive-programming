/*
Author: Davi Augusto Neves Leite
Date: 19/09/2020
*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

bool sortSecond(pair<ll, ll> &a, pair<ll, ll> &b){
    return (a.second < b.second);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    ll n;
    cin >> n;

    vector<pair<ll, ll>> movie;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        movie.push_back(make_pair(a, b));
    }
    sort(movie.begin(), movie.end(), sortSecond);

    ll answer = 1LL;
    ll aux = movie[0].second;

    for(ll i = 1; i < n; i++){
        if(movie[i].first >= aux){
            answer++;
            aux = movie[i].second;
        }
    }

    cout << answer << endl;

    return 0;
}