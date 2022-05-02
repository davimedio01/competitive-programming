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
    
    vector<int> elements;

    int n, i;
    cin >> n;

    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;

        elements.push_back(aux);
    }

    //Verificar se o número da frente é menor do que o anterior e aumentar sua contagem em 1
    ll answer = 0LL;

    for(int i = 1; i < n; i++){
        if (elements[i] < elements[i - 1]){
            answer += abs(elements[i] - elements[i - 1]);
            elements[i] += abs(elements[i] - elements[i - 1]);
        }
    }

    cout << answer << endl;
    
    return 0;
}