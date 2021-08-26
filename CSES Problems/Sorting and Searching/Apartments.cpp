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

    ll maximumDifference;
    cin >> maximumDifference;

    priority_queue<ll> applicant;
    for (int i = 0; i < n; i++) {
        ll desired;
        cin >> desired;

        applicant.push(desired);
    }

    priority_queue<ll> sizeApartment;
    for (int i = 0; i < m; i++) {
        ll apartment;
        cin >> apartment;

        sizeApartment.push(apartment);
    }

    //Verificando se o tamanho do apartamento está entre: ai - maximumDifference e ai + maximumDifference
    ll answer = 0LL;
    while (!applicant.empty() && !sizeApartment.empty()) {
        if ((applicant.top() - maximumDifference) <= sizeApartment.top() && (applicant.top() + maximumDifference) >= sizeApartment.top()) {
            answer++;
            applicant.pop();
            sizeApartment.pop();
        }
        else {
            if (applicant.top() > (sizeApartment.top() + maximumDifference)) {
                applicant.pop();
            }
            else {
                sizeApartment.pop();
            }
        }
    }

    cout << answer << endl;

    return 0;
}