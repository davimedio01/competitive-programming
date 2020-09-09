/*Criado por Davi Augusto - BCC - UNESP Bauru*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX 100

int main(){

    string frase;
    cin >> frase;

    //Analisando os char da frase
    for(int i=frase.size(); i >= 0; i--){
        //Caso sejam iguais, eliminar o intervalo
        if(frase[i] == frase[i+1])
            frase.erase(i,2);
    }
    cout << frase << endl;

    return 0;
}