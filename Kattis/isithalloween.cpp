/*
Author: Davi Augusto Neves Leite
Date: 27/08/2021

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
    
    string month, day;
    cin >> month >> day;

    if((month == "OCT" && day == "31") || (month == "DEC" && day == "25"))
        cout << "yup";
    else
        cout << "nope";

    return 0;
}