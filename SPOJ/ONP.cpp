#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Função Verificar Pilha Vazia
int VerificaVazia(vector<char> pilha){
    return (pilha.size() == NULL);
}
//Função Verificar Sinais
int VerificaSinais(char info){
    return
    (info == '+' || info == '-' || info == '*' || info == '/' || info == '^');
}

//Função Empilhar
void Empilha(vector<char> *pilha, char info){
    (*pilha).push_back(info);
}
//Função Desempilhar
void Desempilha(vector<char> *pilha, char *info){
    if(VerificaVazia((*pilha)))
        return;
    (*info) = (*pilha).back();
    (*pilha).pop_back();
}


int main(){

    int num_casos;
    cin >> num_casos;

    while(num_casos--){

        //USO DO CONCEITO DE PILHA
        vector<char> pilha, sinal;

        //Recuperar valores digitados pelo usuário
        string exp_alg; cin >> exp_alg;
        char aux;

        //Empilhar as letras na "pilha", sinais na "sinal", desempilhar sinais quando encontrado um ")"
        for(int i=0; i<exp_alg.length(); i++){
            if(exp_alg[i] == ')'){
                //Desempilhar Sinais na Pilha
                Desempilha(&sinal, &aux);
                Empilha(&pilha, aux);
            }

            //Empilhando elementos
            if(VerificaSinais(exp_alg[i])){
                Empilha(&sinal, exp_alg[i]);
            }
            else if (exp_alg[i] >= 'a' && exp_alg[i] <= 'z'){
                Empilha(&pilha, exp_alg[i]);
            }
        }
        for(int i=0; i<pilha.size(); i++){
            cout << pilha[i];
        }
        cout << endl;
    }

    return 0;
}
