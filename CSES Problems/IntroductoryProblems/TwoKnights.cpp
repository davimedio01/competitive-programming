/*
Author: Davi Augusto Neves Leite
Date: 15/09/2020

Explicação

Fazer o total possível de ataque/posição menos a combinatória dos cavalos de se atacarem

Total possível: n²*(n² - 1)/2 (dois cavalos posicionados em qualquer lugar do tabuleiro nxn)

A combinatória pode ser encontrada analisando um tabuleiro 2x3 ou 3x2, os quais
formam o "ataque" dos cavalos (em forma de "L" -> 2x3 ou 3x2):

- -     - - - 
- -     - - -
- -     (formas de "L")

Pode-se pensar que existe apenas DUAS maneiras de colocar os cavalos, de
tal forma que eles se ataquem. Com isso, basta contar "quantos" 2x3 e 3x2
quadrados existem em tabuleiros nxn. Ou seja, para 2x3 (ou 3x2):

(n - 1)(n - 2) + (n - 2)(n - 1) = 2(n - 1)(n - 2) [dois cavalos]

Além disso, existem duas maneiras de colocar cada cavalo (2x3 ou 3x2):

2 * [2(n - 1)(n - 2)] = 4 * (n - 1) (n - 2)

Portanto, o total possível de cada cavalo atacar ao outro em um tabuleiro nxn é:

n²*(n² - 1)      4 * (n - 1)(n - 2)
___________   -
    2
*/

#include <bits/stdc++.h>

#define MAX 10002
typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    ll n;
    cin >> n;

    ll k1, k2;
    for(ll i = 1; i <= n; i++){
        //Marca o total de lugares para colocar os cavalos
        k1 = ((i * i) * ((i * i) - 1))/2;

        //Combinação: 2(k - 1) * (k - 2) + 2(k - 1) * (k - 2)
        k2 = 4 * (i - 1) * (i - 2);
        
        cout << k1 - k2 << endl;
    }

    return 0;
}