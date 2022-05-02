/*
Author: Davi Augusto Neves Leite
Date: 09/09/2020
*/

#include <bits/stdc++.h>

#define MAX 1000002
typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    int n;
    cin >> n;

    if(n == 1){
        cout << "1" << endl;
    }
    else if(n == 2 || n == 3){
        cout << "NO SOLUTION" << endl;
    }
    else if(n == 4){
        cout << "2 4 1 3" << endl;
    }
    else{
        //Como: Par - Ímpar  = 1 (sequenciais), basta printar fora dessa ordem
        //Ímpares
        for(int i = 1; i <= n; i += 2){
            cout << i << " ";
        }
        //Pares
        for(int i = 2; i <= n; i += 2){
            cout << i << " ";
        }
    }

    return 0;
}