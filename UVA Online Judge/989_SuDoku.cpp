/*Criado por Davi Augusto - BCC - UNESP Bauru*/
/*
O clássico problema do SuDoKu:
linhas e colunas devem ter a mesma soma,
porém não podem ter elementos iguais

Resolvido com Backtracking:

1 - "Escolhas"
2 - "Restrições"
3 - "Objetivo"

Escolhas: Colocar de 1 a 9 em cada célula da matriz em que SE PERMITE preencher (0)
Restrições: Colocações que não podem quebrar o conceito
            de Sudoku
Objetivos: Completar todas as tabelas

Resolver cada linha, porém voltando a célula anterior se necessário

Ou seja: colocar número em cada célula, sempre verificando
antes se pode ou não colocar aquele número (regra do Sudoku)
1°: encontrar a linha e coluna da célula a ser preenchida (retornando true)
2°: um for com dígitos de 1 a 9, verificando se não há conflito
     (todas as linhas, todas as colunas, sub-matriz em que a célula está contida)
3°: inserir elemento e reiniciar o processo (caso de erro em alguma, atribuir 0 de novo naquela célula)

*/
#include <bits/stdc++.h>
#include <iostream>

#define MAX 9
using namespace std;

//Escopos
bool campoPreencher(int matriz[][MAX], int n, int *linha, int *coluna);
bool permissaoCelula(int matriz[][MAX], int n, int linha, int coluna, int elemento);
bool verificaLinhaMatriz(int matriz[][MAX], int n, int linha, int elemento);
bool verificaColunaMatriz(int matriz[][MAX], int n, int coluna, int elemento);
bool verificaCamposSubMatriz(int matriz[][MAX], int n_sub, int linha_sub, int coluna_sub, int elemento);
bool Sudoku(int matriz[][MAX], int n);


//Verificar o campo a ser preenchido (caso exista)
bool campoPreencher(int matriz[][MAX], int n, int *linha, int *coluna){
     for((*linha)=0; (*linha)<n; (*linha)++){
          for((*coluna)=0; (*coluna)<n; (*coluna)++){
               if(matriz[(*linha)][(*coluna)] == 0)
                    return false;
          }
     }
     return true;
}
//Verifica se é permitido a inserção do elemento com base:
     //Matriz toda: LINHA e COLUNA totais daquela célula
     //Sub-Matriz em análise: TODOS os campos permitirem
bool permissaoCelula(int matriz[][MAX], int n, int linha, int coluna, int elemento)
{
     int tam_sub = sqrt(n); //Tamanho de cada sub-matriz
     return ((verificaLinhaMatriz(matriz, n, linha, elemento)) &&
             verificaColunaMatriz(matriz, n, coluna, elemento) &&
             verificaCamposSubMatriz(matriz, sqrt(n), linha - (linha % tam_sub), coluna - (coluna % tam_sub), elemento) &&
             matriz[linha][coluna] == 0);
}
//Verifica a LINHA INTEIRA da MATRIZ
bool verificaLinhaMatriz(int matriz[][MAX], int n, int linha, int elemento){
     for(int aux = 0; aux < n; aux++){
          if(matriz[linha][aux] == elemento)
               return false; //Não pode inserir por causa de uma linha
     }
     return true; //Pode inserir
}
//Verifica a COLUNA INTEIRA da MATRIZ
bool verificaColunaMatriz(int matriz[][MAX], int n, int coluna, int elemento){
     for(int aux = 0; aux < n; aux++){
          if(matriz[aux][coluna] == elemento)
               return false; //Não pode inserir por causa de uma coluna
     }
     return true; //Pode inserir
}
//Verifica a TODOS OS CAMPOS da SUB-MATRIZ (contém a célula)
bool verificaCamposSubMatriz(int matriz[][MAX], int n_sub, int linha_sub, int coluna_sub, int elemento)
{
     //n_sub = máximo de casas de cada sub-matriz (ex: 9x9 -> 3x3 cada sub-matriz)
          //Com isso, "movemos" a linha/coluna inicial (0..2) até a sub-matriz desejada (ex: L = 0..2/C = 3..5) para análise
          //Para isso, basta pegar a linha do elemento e tirar o resto do valor dessa linha com o tamanho da sub-matriz
     for (int i = 0; i < n_sub; i++)
     {
          for(int j = 0; j < n_sub; j++)
          {
               if (matriz[i + linha_sub][j + coluna_sub] == elemento)
                    return false; //Não pode inserir por causa de uma linha
          }
     }
     return true; //Pode inserir
}

//Função principal
bool Sudoku(int matriz[][MAX], int n)
{
     //Auxiliares da linha e coluna a serem preenchidas
     int linha, coluna;
     //Verifica a linha e coluna que precisa ser preenchida
          //1° Passo do BackTracking
     if(campoPreencher(matriz, n, &linha, &coluna))
          return true; //caso já esteja tudo preenchido

     //Com o campo da linha e coluna, verificamos se a inserção de 1 a 9 é possível
     for(int elemento=1; elemento<=n; elemento++)
     {
          //Caso seja permitido, isto é: Matriz inteira: LINHA e COLUNA inteira permite; Sub-Matriz: TODOS os campos devem permitir
               //2° Passo do BackTracking
          if (permissaoCelula(matriz, n, linha, coluna, elemento)){ 
               //Caso seja permitido, inserir elemento
               matriz[linha][coluna] = elemento;

               //Continuar a verificação recursivamente
               if(Sudoku(matriz, n)){
                    return true; //Recursivo: vai continuando os passos até encerrar os processos
               }
               //Do contrário (caso alguma chamada recursiva retorne falso (abaixo)), atribuir 0 novamente a célula
               matriz[linha][coluna] = 0;
          }
     }
     //Caso seja impossível em alguma operação do "backtracking" (ficar retornando os passos), retornar falso
     return false;
     
}


int main(){

     //Tamanho de uma matriz (n² x n² o total)
     int total, cont = 1;
     while(scanf("%d", &total) != EOF){
          if (cont != 1)
               cout << endl;
          cont = 2;

          //Tamanho do Sudoku
          int tamanho_sudoku = total * total;
          //Matriz contendo o jogo
          int sudoku[MAX][MAX];

          //Salvando elementos
          for (int i = 0; i < tamanho_sudoku; i++)
          {
               for (int j = 0; j < tamanho_sudoku; j++)
               {
                    cin >> sudoku[i][j];
               }
          }
          
          if (Sudoku(sudoku, tamanho_sudoku))
          {
               for (int i = 0; i < tamanho_sudoku; i++)
               {
                    cout << sudoku[i][0];
                    for (int j = 1; j < tamanho_sudoku; j++)
                    {
                         cout << ' ' << sudoku[i][j];
                    }
                    cout << endl;
               }
          }
          else
          {
               cout << "NO SOLUTION" << endl;
          }
          
     }
     
     
     return 0;
}