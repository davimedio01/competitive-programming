/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define max 100000 //10 elevado a 5

//Usa-se set, pois cada resultado da potência de k é único.
set<long long> todasPotencias; 

map<long long, int> aux;

//Armazena as somas parciais
long long somasParciais[max + 2];

void fazSomasParciais(long long qtdeProdutos){
    somasParciais[0] = 0;

    for(int i = 1; i <= qtdeProdutos; i++){
        cin >> somasParciais[i]; //Cada um dos valores de afeto
        somasParciais[i] += somasParciais[i-1];
    }
}

void armazenaPotencias(long long k, long long qtdeProdutos){
    //Elemento neutro da multiplicação
    long long potencias = 1; 
    
    todasPotencias.clear();

    int i = 0;

    //Após exaustivos testes de critérios de parada.......
    //O valor 50 foi escolhido e é necessário para evitar TLE, pode ser
    //um número maior também.
    while(potencias <= 1e14 && i <= 50){
        //Lembrando que 1 também é resultado de uma potência de k, k⁰ = 1.
        todasPotencias.insert(potencias); 
        potencias *= k;
        i++;
    }

}

long long totalSegmentosValidos(long long qtdeProdutos){
    long long totalSegmentos = 0;
    
    aux.clear();

    aux[0] = 1;
    for(int i = 1; i <= qtdeProdutos; i++){
        aux[somasParciais[i]]++;
        for(auto j = todasPotencias.begin(); j != todasPotencias.end(); j++)
            totalSegmentos += aux[somasParciais[i] - *j];
    }
    return totalSegmentos;
}

int main(){
    
    long long int qtdeProdutos, k;
    
    //Número de produtos químicos e o número.
    cin >> qtdeProdutos >> k;

    fazSomasParciais(qtdeProdutos);

    //Posso armazenar agora as potências de k
    armazenaPotencias(k, qtdeProdutos);

    cout << totalSegmentosValidos(qtdeProdutos) << endl;


}
