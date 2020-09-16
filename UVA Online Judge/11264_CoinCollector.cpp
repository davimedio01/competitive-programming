/*
Luis Henrique Morelli
Coin Collector
https://vjudge.net/problem/UVA-11264/
07/09/2020
*/

#include <bits/stdc++.h>

#define MAX

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    
    int T;

    cin >> T;

    while(T--){
        int N;

        cin >> N;

        vector<int> coins;

        for(int i = 0; i < N; i++){
            int a;

            cin >> a;

            coins.push_back(a);
        }

        int withdraw, diffCoins;

        withdraw = coins[0];

        N > 1 ? diffCoins = 2 : diffCoins = 1;

        for(int i = 1; i < N - 1; i++){
            if(withdraw + coins[i] < coins[i + 1]){
                withdraw += coins[i];
                diffCoins++;
            }
        }

        cout << diffCoins << "\n";
    }    
    
    return 0;
}