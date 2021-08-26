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
    
    /*
        n: number of friends
        
        k: bottles of drink
        l: milliliters of the drink
        
        c: number of limes
        d: number of slices of limes

        p: grams of salt

        nl: milliliters of the drink that each friend needs
        np: grams of salt that each friend needs
    */

    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    //Total of milliliters of the drink
    int totalMLDrinks = k * l;
    //Total of Toast, initially
    int toastInitially = totalMLDrinks / nl;

    //Total of Lemons for toast
    int lemonsToast = c * d;

    //Total of Salt for toast
    int saltToast = p / np;

    //Answer
    int answer = min(min(toastInitially, lemonsToast), saltToast) / n;

    cout << answer << endl;
    
    return 0;
}