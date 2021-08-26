#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int BinarioInvertidoToDec(long long int decimal);

int main(){

    int casos;
    long long int numero;

    cin >> casos;

    for(int i = 0; i<casos; i++){
        cin >> numero;
        if(numero % 2 == 0){

            //Conversão de Decimal para Binário e Resultado Final
            cout << BinarioInvertidoToDec(numero) << endl;
        }
        else{
            cout << numero << endl;
        }

    }
    
    return 0;
}

long long int BinarioInvertidoToDec (long long int decimal){

    //Conversão para Binário (Invertido)
    vector<int> bin;
    while(decimal){
        bin.push_back(decimal%2);
        decimal /= 2;
    }

    long long int numeroinvertido = 0;
    long long int aux = 1;

    for(long long int i=bin.size()-1; i >=0; i--){
        if(bin[i] == 1){
            numeroinvertido += aux;
        }
        aux *= 2;
    }

    return numeroinvertido;
}