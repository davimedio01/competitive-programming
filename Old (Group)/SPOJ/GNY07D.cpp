#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 20

void ConvertBinEspiral(string binario, int linha_final, int coluna_final, string *final);
void Descriptografar(string *final, string aux);

int main(){

    int casos;
    scanf("%d", &casos);

    int contcasos = 1;

    while(casos--){
        
        int linha, coluna;
        string binario;
        cin >> linha >> coluna >> binario;

        string final = {};
        ConvertBinEspiral(binario, linha, coluna, &final);

        cout << contcasos++ << " " << final << endl;   
    }
    
    return 0;
}

void ConvertBinEspiral(string binario, int linha_final, int coluna_final, string *final){

    //Convertendo o binario em uma matriz de char
    int k = 0;
    char matriz[linha_final][coluna_final] = {};
    for(int i = 0; i < linha_final; i++){
        for(int j = 0; j < coluna_final; j++){
            matriz[i][j] = binario[k];
            k++;
        }
    }

    //Leitura em Espiral e Conversão em Binário para a string final
    int i, linha_inicio = 0, coluna_inicio = 0; //Auxiliares marcando inicio de linha e coluna
    string aux = {};

    while (linha_inicio < linha_final && coluna_inicio < coluna_final){

        //Horizontal-Direita = Linha
        for(i = coluna_inicio; i < coluna_final; ++i){
            aux += matriz[linha_inicio][i];
            if (aux.size() == 5)
            {
                Descriptografar(&(*final), aux);
                aux.clear();
            }
        }
        linha_inicio++;

        //Vertical-Baixo = Coluna
        for(i = linha_inicio; i < linha_final; ++i){
            aux += matriz[i][coluna_final - 1];
            if (aux.size() == 5)
            {
                Descriptografar(&(*final), aux);
                aux.clear();
            }
        }
        coluna_final--;

        //Horizontal-Esquerda = Linha
        if(linha_inicio < linha_final){
            for(i = coluna_final-1; i >= coluna_inicio; --i){
                aux += matriz[linha_final - 1][i];
                if (aux.size() == 5)
                {
                    Descriptografar(&(*final), aux);
                    aux.clear();
                }
            }
            linha_final--;
        }

        //Vertical-Cima = Coluna
        if(coluna_inicio < coluna_final){
            for(i = linha_final-1; i >= linha_inicio; --i){
                aux += matriz[i][coluna_inicio];
                if (aux.size() == 5)
                {
                    Descriptografar(&(*final), aux);
                    aux.clear();
                }
            }
            coluna_inicio++;
        }
    }
}

void Descriptografar(string *final, string aux){

    //Descriptografar: converter o binário da "aux" em inteiro e transformar isso em um caractere (conforme exercício)
    int decimal_aux = 0, aux_pot = 1;

    //Convertendo Binário de 5 dígitos em Decimal
    for(int i=4; i>=0; i--){
        if(aux[i] == '1'){
            decimal_aux += aux_pot;
        }
        aux_pot *= 2;
    }

    //Utilização da Tabela ASCII
    char caractere;

    if(decimal_aux == 0){
        caractere = 32;
    }
    else{
        caractere = (decimal_aux + 64); //A = 65 em ASCII
    }

    //Retornando na string "final" (resultado exercício)
    (*final) += caractere;
}