/*Criado por Davi Augusto*/

#include <bits/stdc++.h>
#include <iostream>

#define MAX_CONECTA 100002
#define MAX_COORD 1002

using namespace std;

int num_cidades, limite_estados;
vector<int> Conexao(MAX_CONECTA);
vector<double> X(MAX_COORD), Y(MAX_COORD);
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

void Kruskal()
{
     //Respostas (*aux marca a quantidade de cidades no mesmo estado)
     int estados = 0, aux = 0;
     double estradas = 0.0, ferrovias = 0.0;

     //Ordenando por peso (crescente)
     sort(ListaAdj.begin(), ListaAdj.end());

     //Auxiliares
     int cid1, cid2;

     for (int i = 0; i < ListaAdj.size(); i++)
     {
          cid1 = ListaAdj[i].second.first;
          cid2 = ListaAdj[i].second.second;

          //Verificando se a conexão já existe (evitar redundância)
          if (VerificaConexao(cid1, cid2) == false)
          {
               UniaoArvore(cid1, cid2);

               //Verificando se a distância é entre cidades do mesmo Estado (Estrada) e aumentando o contador para "2 cidades" (retirar do número de cidades depois)
               if(ListaAdj[i].first <= limite_estados){
                    aux++;
                    estradas += ListaAdj[i].first;
               }
               else{
                    ferrovias += ListaAdj[i].first;
               }
          }
     }
     
     //O número de estados será dado pela diferença entre o número total de cidades e a repetição de duas cidades (procuradas acimas)
     estados = num_cidades - aux;
     printf("%d %.lf %.lf\n", estados, estradas, ferrovias);
}

int main(){

     double X_aux, Y_aux, distancia;

     int casos, aux_saida = 1;
     cin >> casos;

     while(casos--){
          
          cin >> num_cidades >> limite_estados;

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

          cout << "Case #" << aux_saida++ << ": ";
          Kruskal();
     }
     
     return 0;
}