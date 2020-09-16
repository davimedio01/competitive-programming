#include<bits/stdc++.h>
    
using namespace std;
    

int main(){
    
    //Como esse exercício se trata de grafos, então é necesário interpretá-lo como uma ou mais árvores
    //onde cada nó pai é o gerente e o nó filho o empregado
    //Portanto, o tamanho máximo da árvore corresponde ao mínimo de grupos necessários

    void encontraMinGrupos(vector<int> subordinados[], int aux, int nivel, int *min);

    vector<int> subordinados[2001]; //Vetor de vetores, ou seja, uma matriz.
    int min = 0;
    int numEmpregados, aux;
    cin >> numEmpregados;
    
    for(int i = 1; i <= numEmpregados; i++){
        cin >> aux;
        if(aux == -1){
            subordinados[0].push_back(i); //Na linha inicial terão todos os empregados sem gerente imediato
        }
        else{
            subordinados[aux].push_back(i); //Uma linha da minha matriz para poder juntar todos os empregados subordinados
            //do gerente aux
        }
        /*
            Ex.: Entrada -> 5 empregados -> {-1, 1, 2, 1 , -1}
            A matriz ficará:
            subordinados[-1] = 1 5
            subordinados[1]  = 2 4
            subordinados[2]  = 3
        */    
    }
    
    for(int i = 0; i < subordinados[0].size(); i++){
        //Para o mesmo exemplo, envia-se a matriz completa e percorre-se o vetor de empregados sem chefe.
        //Pois, eles serão a raiz, visto que na hierarquia não existe ninguém acima.
        //Para cada empregado sem chefe, tem-se uma árvore associada.
        encontraMinGrupos(subordinados, subordinados[0][i], 1, &min);
    }
    cout << min << endl;
    return 0;
}

void encontraMinGrupos(vector<int> subordinados[], int aux, int nivel, int *min){
    *min = max(*min, nivel); //Calcula os próximos níveis da árvore
    for(int i = 0; i < subordinados[aux].size(); i++){
        //Percorre todos os filhos do nó em questão
        encontraMinGrupos(subordinados, subordinados[aux][i], nivel + 1, &(*min));
    }
    /* Árvore do gerente 1 vai ficar:
                          1                    
                 2               4
            3
    */

    // Árvore do gerente 5 vai ficar:
    //                     5
}