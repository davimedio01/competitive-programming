/*Criado por Davi Augusto - BCC - UNESP Bauru*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    vector<string> contas;
    vector<int> qtd;
    int n_testes, n_contas;
    cin >> n_testes;

    while(n_testes--){

        //Zerar os Vector's
        contas.clear();
        qtd.clear();
        
        //Solicitando numero de contas e ordenando
        cin >> n_contas;
        cin.ignore();

        string aux_conta;
        for(int i=0; i<n_contas; i++){
            getline(cin, aux_conta);
            contas.push_back(aux_conta);
        }
        //cout << contas.size() << endl;
        sort(contas.begin(), contas.end());

        //Verificando as contas iguais e colocando sequencialmente no contador
        int cont = 1;
        for(int i=0; i<contas.size()-1; i++){
            if(contas[i] == contas[i+1]){
                cont++;
            }
            else{
                qtd.push_back(cont);
                cont = 1;
            }
        }
        qtd.push_back(cont);

        //Mostrando na tela as contas iguais e o contador
        int j;
        cont = 0;
        for(j=0; j<contas.size(); j++){
            if(contas[j] != contas[j+1]){
                cout << contas[j] << " ";
                cout << qtd[cont] << endl;
                cont++;
            }
        } //Printar o último
        if(contas[j] != contas[j+1]){
            cout << contas[j] << " ";
            cout << qtd[cont] << endl;
        }

    }

    return 0;
}