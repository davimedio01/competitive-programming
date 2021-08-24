/*
Author: Davi Augusto Neves Leite
Date: 24/06/2021

Compilar com os argumentos: -O2 -Wall -Wextra
Executar com os argumentos: < input.txt > output.txt
*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int numSoldier;
    cin >> numSoldier;

    vector<int> heightSoldier;
    for(int i = 0; i < numSoldier; i++){
        int height;
        cin >> height;

        heightSoldier.push_back(height);
    }

    int minimumDiff = INT_MAX, diff = 0;
    pair<int, int> soldiers;

    for(int i = 1; i < numSoldier; i++){

        diff = abs(heightSoldier[i] - heightSoldier[i - 1]);
        if(diff < minimumDiff){
            minimumDiff = diff;
            soldiers.first = i - 1;
            soldiers.second = i;
        }
    }

    //Checking the first and last (circle)
    diff = abs(heightSoldier[numSoldier - 1] - heightSoldier[0]);
    if (diff < minimumDiff){
        minimumDiff = diff;
        soldiers.first = numSoldier - 1;
        soldiers.second = 0;
    }

    cout << soldiers.first + 1 << " " << soldiers.second + 1 << endl;

    return 0;
}