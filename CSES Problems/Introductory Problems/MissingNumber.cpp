/*
Author: Davi Augusto Neves Leite
Date: 09/09/2020
*/

#include <bits/stdc++.h>

#define MAX 200005
typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    vector<bool> numbers (MAX, true);
    int n;

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int aux;
        cin >> aux;

        numbers[aux] = false;
    }

    //Verifica qual dos números está faltando
    for(int i = 1; i < MAX; i++){
        if(numbers[i] == true){
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}