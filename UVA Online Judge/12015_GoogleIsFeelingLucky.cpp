#include <iostream>
#include <string>
#include <stdio.h>

#define max 100
using namespace std;

typedef struct{
    char site[max];
    int ranking;
}Sites;

int main(){

    int n, aux = 0, casos = 0;
    cin >> n;

    Sites sites[10];
    while(n > 0){

        //Analisando de 10 em 10
        for(int i=0; i<10; i++){
            cin >> sites[i].site >> sites[i].ranking;
        }

        //Aux = supor que o maior esteja na primeira posição e encontrar o maior de fato
        aux = sites[0].ranking;
        for(int i=1; i<10; i++){
            if(sites[i].ranking > aux)
                aux = sites[i].ranking;
        }

        //Resultado final
        cout << "Case #" << ++casos << ":\n";
        for(int i=0; i<10; i++){
            if(sites[i].ranking == aux)
                cout << sites[i].site << endl;
        }

        aux = 0;
        n--;
    }

    return 0;
}