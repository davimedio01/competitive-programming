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
    
    char problem;
    string number1("\0"), number2("\0");
    int num1, num2;
    bool firstNumber = true;

    ll answer = 0;
    while(scanf("%c", &problem) != EOF){
        
        //Se "firstNumber == true", é o primeiro número
        if(firstNumber == true && (problem != '-' && problem != ';')){
            number1 += problem;
        }
        //Se "firstNumber == false", é o segundo número
        else if(firstNumber == false && (problem != '-' && problem != ';')){
            number2 += problem;
        }
        //Quando houver "-", salva o próximo número em outra variável
        else if(problem == '-'){
            //Basta trocar o valor da booleana
            firstNumber = false;
        }
        //Quando houver ";", termina a leitura dos números e faz a operação
        else if(problem == ';'){
            //Se tiver um número, só é contado um    
            if(firstNumber){
                answer++;
            }
            else{
                //Atribui os números como inteiros
                num1 = stoi(number1);
                num2 = stoi(number2);

                //Conta o intervalo entre os números, inclusivo
                answer += (abs(num1 - num2) + 1);
            }

            firstNumber = true;
            number1 = "\0";
            number2 = "\0";
        }
    }

    //Realizando a última iteração (último(s) número(s))
    if(firstNumber){
        answer++;
    }
    else{
        //Atribui os números como inteiros
        num1 = stoi(number1);
        num2 = stoi(number2);

        //Conta o intervalo entre os números, inclusivo
        answer += (abs(num1 - num2) + 1);
    }

    cout << answer;


    return 0;
}