/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*

Resolvido com Backtracking:

1 - "Escolhas"
2 - "Restrições"
3 - "Objetivo"

Escolhas: Colocar dígitos de 0 a 9 na senha com base nas "regras" (# e 0)
Restrições: Regras e o dígito (ex: #0). O '#' ficará a palavra e o dígito '0' os números de 0 a 9. Printar crescente.
Objetivos: Mostrar todo o conjunto de senha com as regras dadas

Critério de parada: dígito alcançar 9 (i <= 9); forem todas as palavras do vetor; 
                    todos dígitos disponíveis

Padrão:

1) Ir até o final da regra;
2) Ver qual campo é:
     -> Se for '#', mostrar a palavra atual
     -> Se for '0', mostrar dígitos de 0 a 9; CONTUDO...
3) Necessário mostrar crescente...


Ciclo até fim do vector de palavras
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Função para Mostrar todas as Palavras
void mostraPalavras(vector<string> dicio, vector<string> auxfinal){
     for(int i = 0; i < dicio.size(); i++){
          for(int j = 0; j < auxfinal.size(); j++){
               cout << auxfinal[j];
          }
          cout << dicio[i] << endl;
     }
}
//Função para Mostrar todos os Dígitos (0 a 9)
void mostraDigitos(vector<string> auxfinal){
     for (int i = 0; i <= 9; i++)
     {
          for (int j = 0; j < auxfinal.size(); j++)
          {
               cout << auxfinal[j];
          }
          cout << i << endl;
     }
}

//Backtracking
void resolveSenha(vector<string> dicio, string regra,
                  int caracRegra, vector<string> auxfinal)
{
     //Caso chegue no último, analisar
     if(caracRegra == (regra.length()-1)){
          //Verificar o caractere correspondente e printar
          //Dígito
          if (regra[caracRegra] == '0'){
               mostraDigitos(auxfinal);
          }
          else if (regra[caracRegra] == '#'){ //Palavra
               mostraPalavras(dicio, auxfinal);
          }
          return;
     }

     //Dígito
     if(regra[caracRegra] == '0'){
          for(int i = 0; i <= 9; i++){
               //Copiar o dígito pra auxiliar
               auxfinal.push_back(to_string(i));

               //Executando a função novamente e avançando o dígito da regra
               resolveSenha(dicio, regra, caracRegra + 1, auxfinal);

               //Removendo o Último Elemento da Auxiliar
               auxfinal.pop_back();
          }
     }
     else if(regra[caracRegra] == '#'){ //Palavra
          for(int j = 0; j < dicio.size(); j++){
               //Copiar a palavra pra auxiliar
               auxfinal.push_back(dicio[j]);
          
               //Executando a função novamente e avançando o dígito da regra
               resolveSenha(dicio, regra, caracRegra + 1, auxfinal);
               
               //Removendo o Último Elemento da Auxiliar
               auxfinal.pop_back();
          }
     }
}

int main(){

     int numpalavras, numregras;
     while(cin >> numpalavras){
          //Vector contendo Dicionário
          vector<string> dicionario;
          dicionario.clear();
          string dicioaux;

          //Lendo cada palavra
          for(int i = 0; i < numpalavras; i++){
               cin >> dicioaux;
               dicionario.push_back(dicioaux);
          }

          //Lendo Qtd de Regras
          cin >> numregras;

          //Vector contendo as regras
          vector<string> regras;
          regras.clear();
          string regraux;

          //Lendo cada regra
          for(int i = 0; i < numregras; i++){
               cin >> regraux;
               regras.push_back(regraux);
          }


          //Mostrando resultado (Backtracking)
          cout << "--" << endl;
          //Passar cada regra
          vector<string> auxfinal;
          for(int i = 0; i < numregras; i++){
               auxfinal.clear();
               resolveSenha(dicionario, regras[i], 0, auxfinal);
          }

     }
     
     return 0;
}