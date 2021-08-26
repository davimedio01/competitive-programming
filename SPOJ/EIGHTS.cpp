#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    //Encontrar todos os número em que o cubo termina em 888
        //Ex: 192³ = 7077888

    long long int k;
    int t;
    cin >> t;

    for(int i = 0; i<t; i++){

        cin >> k;

        //Fórmula: 192+250*(k-1)
        cout << 192+250*(k-1) << endl;
    }
    
    return 0;
}