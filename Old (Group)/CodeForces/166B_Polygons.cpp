/*
Verificação se todos os pontos do polígono B estão dentro do polígono A.

Para isso:
1) Em cada ponto, prolongar uma semirreta para o infinito à direita.
2) Basta verificar se a quantidade de intersecção até a última aresta
do polígono A é par (não pertence) ou ímpar (pertence).

Este exercício considera:
! - Polígono A e B não degenerados;
! - Vértices dados em ordem horária.

! Baseado nos conceitos de intersecção e orientação:
http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
! Além disso, o método utilizado aqui consiste na relação
! entre a orientação das retas e intersecção com a separação
! do polígono A em sub-triângulos (por meio dos vértices).
! Diante disso, é realizado a "busca binária" por meio dos ângulos.

*/

#include <bits/stdc++.h>
#include <iostream>

#define LONG_INFINITO 1000000005
#define MAX_VETOR 100002

using namespace std;

struct Ponto
{
     long long x, y;
};

Ponto poligonoA[MAX_VETOR], poligonoB[MAX_VETOR];

//Escopos
bool VerificaPoligonoDentroPoligono(long nA, Ponto B);
long long VerificaOrientacao(Ponto ponto1, Ponto ponto_meio, Ponto ponto2);

//Funções
bool VerificaPoligonoDentroPoligono(long nA, Ponto B)
{

     //Verificando a Orientação entre os pontos primordiais de A (casos base)
     if (VerificaOrientacao(poligonoA[0], poligonoA[1], B) <= 0 ||
         VerificaOrientacao(poligonoA[nA - 1], poligonoA[0], B) <= 0)
          return false;

     //Com isso, necessário um contador de intersecções deste Ponto de B com arestas de A
     long long esq = 1, dir = nA - 1;

     //"Busca Binária"
     while (dir - esq > 1)
     {
          long long meio = (esq + dir)/2;

          //Analisando
          if (VerificaOrientacao(poligonoA[0], poligonoA[meio], B) > 0)
          {
               esq = meio;
          }
          else
          {
               dir = meio;
          }  
     }

     return (VerificaOrientacao(poligonoA[esq], poligonoA[dir], B) > 0);
}

long long VerificaOrientacao(Ponto ponto1, Ponto ponto_meio, Ponto ponto2)
{
     //Conceitos da Orientação de Retas com Intersecção
     /*
     1) = 0: colineares;
     2) > 0: para a direta;
     3) < 0: para a esquerda;
     */
     return ((ponto2.x - ponto_meio.x) * (ponto_meio.y - ponto1.y) - (ponto2.y - ponto_meio.y) * (ponto_meio.x - ponto1.x));
}

bool VerificaColinear(Ponto ponto1, Ponto ponto_meio, Ponto ponto2)
{
     //Verificando se os pontos são colineares
     if (ponto_meio.x <= max(ponto1.x, ponto2.x) &&
         ponto_meio.x >= min(ponto1.x, ponto2.x) &&
         ponto_meio.y <= max(ponto1.y, ponto2.y) &&
         ponto_meio.y >= min(ponto1.y, ponto2.y))
          return true;

     return false;
}

int main(){

     //Quantidade de Pontos 
     long nA, nB;

     //Polígono A
     cin >> nA;
     for(long i = 0; i < nA; i++)
     {
          cin >> poligonoA[i].x >> poligonoA[i].y;
     }

     //Polígono B
     cin >> nB;
     for (long i = 0; i < nB; i++)
     {
          cin >> poligonoB[i].x >> poligonoB[i].y;
     }

     //Percorrendo o Polígono B para analisar cada ponto
     for(long i = 0; i < nB; i++)
     {
          //Realizando a verificação
          if (!VerificaPoligonoDentroPoligono(nA, poligonoB[i]))
          {
               cout << "NO" << endl;
               return 0;
          }
     }
     
     cout << "YES" << endl;
     return 0;
}