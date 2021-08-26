/*
Author: Davi Augusto Neves Leite
Date: 27/06/2021

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
    
    int n;
    cin >> n;
    
    pair<int, int> minimum, maximum;

    minimum.first = minimum.second = INT_MAX;
    maximum.first = maximum.second = INT_MIN;

    for(int i = 0; i < n; i++){
        int height;
        cin >> height;

        if(minimum.second >= height){
            minimum.first = i; //Position of Min Height
            minimum.second = height;
        }
        if(maximum.second < height){
            maximum.first = i; //Position of Max Height
            maximum.second = height;
        }
    }
    
    //Counter of Swap's
    int countSwap = 0;

    //Comparing Position of Maximum and Minimum
    if(minimum.first > maximum.first){
        countSwap = (n - 1) - minimum.first + maximum.first;
    }
    else{
        //-2 => number of swap for minimum in maximum/maximum in minimum (ex: in seconde case, change 76 with 10 and 10 with 76 its the same, but we have to count 1!)
        countSwap = ((n - 1) - 1) - minimum.first + maximum.first;
    }

    cout << countSwap << endl;

    return 0;
}