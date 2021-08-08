/*
Deve-se analisar cada linha separadamente, com base em duas comparações:

I) Procurar o máximo possível na linha, excluindo adjacente

II) Verificar máximo entre linhas adjacentes (ex: 1° com 2°; 2° com 1° e 3°; ...)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, doce;

    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }

        int linhaAnterior, linhaPosterior, aux;

        linhaAnterior = 0;
        linhaPosterior = 0;

        for(int i = 0; i < n; i++){
            int numAnterior, numPosterior;

            numAnterior = 0;
            numPosterior = 0;

            for(int j = 0; j < m; j++){
                cin >> doce;
                
                //Analisando o máximo de cada linha: verifica com a soma anterior adjacente o maior possível
                aux = numAnterior;
                numAnterior = max(numAnterior, numPosterior + doce);
                numPosterior = aux;
            }

            //Analisando o máximo entre linhas: mesma verificação do anterior
            aux = linhaAnterior;
            linhaAnterior = max(linhaAnterior, linhaPosterior + numPosterior);
            linhaPosterior = aux;
        }

        cout << linhaPosterior << endl;

    }
    
    return 0;
}