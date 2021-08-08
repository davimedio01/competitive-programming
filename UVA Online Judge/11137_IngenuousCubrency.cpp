#include <iostream>
#include <bits/stdc++.h>

#define MAX 10001

using namespace std;

/*
by: Davi Augusto

Baseado no algoritmo do problema da mochila,
utiliza-se de um vetor contendo todos os valores do dinheiro
(cube[]) possíveis. Então é utilizado outro vetor auxilar
(mochila[]) contendo todos os resultados possíveis para a soma
de valores de dentro do cube[] dar N (usuário digitar).

Primeiramente, é necessário dar o valor da posição 0 do
vetor auxiliar, já que utiliza-se as posições reais do 
vetor dinheiro (cube[]) para calcular as 
combinações possíveis (ex. cube[1] = 1*1*1;
cube[2] = 2*2*2;...) por meio de dois laços for
(construção de uma "matriz", assim como no algoritmo
do problema da mochila). Como na posição 0 seria como 
"a soma N dar 0", então indica-se com valor 1 
(pois 0*0*0=0, tem-se somente uma forma de dar esse valor).
O índice i controla o valor das moedas (cube[i]) e o
índice j controla o vetor auxiliar (como forma de matriz), 
para que se possa calcular as combinações possíveis.
Assim, tem-se o vetor auxiliar tendo os valores 
das combinações nas suas posições reais.*/

int main(){

    //Vetor com todas as moedas
    vector<int> cube;
    for(int i=1; i<=21; i++){
        cube.push_back(i*i*i);
        //cout << cube[i-1] << endl;
    }

    //Vetor Auxiliar Vazio para cálculo das combinações
    unsigned long long int comb[MAX] = {};
    comb[0] = 1; //Primeira posição
    for(int i=0; i<21; i++){
        for(int j=cube[i]; j<MAX; j++){
            comb[j] += comb[j - cube[i]];
        }
    }

    int num;
    while(scanf("%d", &num) != EOF){
        cout << comb[num] << endl;
    }

    return 0;
}
