/*
Author: Davi Augusto Neves Leite
Date: 17/09/2020
*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    int n, m;
    cin >> n >> m;

    multiset<ll> priceTicket;
    for (int i = 0; i < n; i++) {
        ll price;
        cin >> price;

        priceTicket.insert(price);
    }

    for (int i = 0; i < m; i++) {
        ll consumer;
        cin >> consumer;

        auto it = priceTicket.lower_bound(consumer);

        //FELIPE É FODA!
        if ((it == priceTicket.begin() && (*it) > consumer) || priceTicket.size() == 0) {
            cout << "-1" << endl;
        }
        else {
            if (it == priceTicket.end() || (*it) > consumer) {
                it--;
            }
            cout << (*it) << endl;
            priceTicket.erase(it);
        }

    }

    return 0;
}