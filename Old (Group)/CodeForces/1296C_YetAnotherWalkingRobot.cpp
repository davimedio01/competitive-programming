/*Criado por Davi Augusto - BCC - UNESP Bauru*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
    O exercício consistem em, dado os comandos de um robô num eixo de coordenadas
    (x,y), de modo que o início que ele esteja seja igual ao fim, remover a sub-string
    do menor caminho. Caso não seja possível, printar -1.
    Caso possível, printar a primeira que foi removida (pode ter mais de uma).
    
    Para encontrar o caminho mais curto, utilizei de um map (matriz) "final"
    que indica, para cada ponto do caminho percorrido, o número máximo de operações "i"
    de tal forma que permaneceremos nesse ponto. Assim, basta analisar cada caracter
    dos comandos digitados, começando a contar a partir de i+1 (haja visto que 
    a primeira coordenada sempre é "nova" na matriz).

    Caso este ponto já esteja na matriz, representando um caminho já percorrido
    do ciclo, então basta verificar se a duração deste ciclo (índice do map) é menor
    que a anterior (para isso, basta armazenar sempre essa duração em duas variáveis:
    esq_dir e cima_baixo, uma com o índice da matriz e outra com a quantidade "i" andada
    pelo robô).
*/


int main(){

    int num_casos;
    cin >> num_casos;

    while(num_casos--){

        //Utilização de Map e Pair
        pair<int, int> pos;
        pos = {0, 0}; //Posição inicial do Robo
        map<pair<int, int>, int> final; //Matriz de Posições
        final[pos] = 0;

        //String e Auxiliares das posições
        int num_comandos;
        string comandos;
        cin >> num_comandos >> comandos;
        int indice_ciclo = -1, qtd_passos_ciclo = num_comandos; //Auxiliares para contar os ciclos repetidos

        //Analisando as posições (x,y) e movendo o par "pos" conforme a string
        for(int i=0; i<num_comandos; ++i){
            if(comandos[i] == 'L')
                --pos.first;
            if(comandos[i] == 'R')
                ++pos.first;
            if(comandos[i] == 'U')
                ++pos.second;
            if(comandos[i] == 'D')
                --pos.second;
            
            /*
            Aqui está o principal do problema. O map, como uma matriz, armazena
            em seus índices os pares caminhados pelo robô. Esse primeiro if
            refere-se se o caminho já foi percorrido pelo robô.
            
            Caso o caminho já tenha sido percorrido pelo robô (ex. de (0,0) ele
            foi para (0,1) e depois voltou para (0,0)), basta verificar se esse ciclo
            tem duração menor que o anterior (se for o primeiro, sempre terá).
            Para isso, basta armazenar o valor do índice em uma variável e o valor
            da quantidade "i" já caminhada pelo robô em outra variável e fazer
            a verificação de equivalência do atual para o anterior.

            Portanto, a primeira auxiliar marca o índice do par em que o robô
            volta para o ciclo e a segunda auxiliar marca a quantidade de passos
            em que ele fez isso.
            */
            if(final.count(pos)){
                if (i - final[pos] + 1 < qtd_passos_ciclo - indice_ciclo + 1)
                {
                    indice_ciclo = final[pos];
                    qtd_passos_ciclo = i;
                }
            }
            final[pos] = i + 1;
        }
        if (indice_ciclo == -1)
            cout << "-1" << endl;
        else
            cout << indice_ciclo + 1 << " " << qtd_passos_ciclo + 1 << endl;
    }
    

    return 0;
}