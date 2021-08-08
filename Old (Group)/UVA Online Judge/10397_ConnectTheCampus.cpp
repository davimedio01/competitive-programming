/*Criado por Davi Augusto*/

#include <bits/stdc++.h>
#include <iostream>

#define MAX 1001

using namespace std;

int num_cidades;
vector<int> Conexao(MAX);
vector<double> X(MAX), Y(MAX);
vector<pair<double, pair<int, int>>> ListaAdj;

//Inicia o vetor de Conexao com número das estações
void iniciaConexao()
{
     Conexao.assign(num_cidades, 0);
     for (int i = 0; i < num_cidades; i++)
     {
          Conexao[i] = i;
     }
}

//Busca pela Conexão
int BuscaConexao(int x)
{
     while (Conexao[x] != x)
     {
          Conexao[x] = Conexao[Conexao[x]];
          x = Conexao[x];
     }
     return x;
}

//Verificação da Existência da Conexão
bool VerificaConexao(int x, int y)
{
     return BuscaConexao(x) == BuscaConexao(y);
}

//União dos Elementos na árvore
void UniaoArvore(int x, int y)
{
     Conexao[BuscaConexao(x)] = BuscaConexao(y);
}

double Kruskal()
{
     //Ordenando por peso (crescente)
     sort(ListaAdj.begin(), ListaAdj.end());

     //Auxiliares
     double custo_min = 0, custo_atual;
     int cid1, cid2;

     for (int i = 0; i < ListaAdj.size(); i++)
     {
          cid1 = ListaAdj[i].second.first;
          cid2 = ListaAdj[i].second.second;
          custo_atual = ListaAdj[i].first;

          //Verificando se a conexão já existe (evitar redundância)
          if (VerificaConexao(cid1, cid2) == false)
          {
               custo_min += custo_atual;
               UniaoArvore(cid1, cid2);
          }
     }

     return custo_min;
}

int main(){

     double X_aux, Y_aux, distancia;
     int cabos_cidades, cid1, cid2;

     while(cin >> num_cidades){

          //Limpando e Iniciando Variáveis
          X.clear();
          Y.clear();
          ListaAdj.clear();
          iniciaConexao();

          //Leitura das Cidades (X e Y)
          for(int i = 0; i < num_cidades; i++){
               cin >> X_aux >> Y_aux;
               X.push_back(X_aux);
               Y.push_back(Y_aux);
          }

          //Realizando a distância entre cidades e acrescentando na Lista
          for(int i = 0; i < num_cidades; i++){
               for(int j = i + 1; j < num_cidades; j++){
                    distancia = hypot(X[i] - X[j], Y[i] - Y[j]);
                    ListaAdj.push_back(make_pair(distancia, make_pair(i, j)));
               }
          }

          //Leitura dos cabos existentes
          cin >> cabos_cidades;
          //Acrescetando na "Árvore de Conexões"
          for(int i = 0; i < cabos_cidades; i++){
               cin >> cid1 >> cid2;
               UniaoArvore(cid1 - 1, cid2 - 1);
          }

          printf("%.2lf\n", Kruskal());
     }
     
     return 0;
}