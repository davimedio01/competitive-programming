/*Criado por Davi Augusto*/

#include <bits/stdc++.h>
#include <iostream>

#define MAX_STATION 79802 

using namespace std;

int num_estacao, num_conexao;
vector<int> Conexao(MAX_STATION);
vector<pair<int, pair<int, int>>> ListaAdj;
map<string, int> EstacaoId;

//Inicia o vetor de Conexao com número das estações
void iniciaConexao(int num_estacao)
{
     Conexao.assign(num_estacao, 0);
     for(int i = 0; i < num_estacao; i++){
          Conexao[i] = i;
     }
}

//Busca pela Conexão
int BuscaConexao(int x){
     while(Conexao[x] != x){
          Conexao[x] = Conexao[Conexao[x]];
          x = Conexao[x];
     }
     return x;
}

//Verificação da Existência da Conexão
bool VerificaConexao(int x, int y){
     return BuscaConexao(x) == BuscaConexao(y);
}

//União dos Elementos na árvore
void UniaoArvore(int x, int y){
     Conexao[BuscaConexao(x)] = BuscaConexao(y);
}

long long Kruskal(int *valConexaoa_krustal)
{
     //Ordenando por peso (crescente)
     sort(ListaAdj.begin(), ListaAdj.end());

     //Auxiliares
     long long custo_min = 0, custo_atual;
     int est1, est2;

     (*valConexaoa_krustal) = 0;
     for(int i = 0; i < num_conexao; i++)
     {
          est1 = ListaAdj[i].second.first;
          est2 = ListaAdj[i].second.second;
          custo_atual = ListaAdj[i].first;

          //Verificando se a conexão já existe (evitar redundância)
          if(VerificaConexao(est1, est2) == false){
               custo_min += custo_atual;
               UniaoArvore(est1, est2);
               (*valConexaoa_krustal)++;
               if((*valConexaoa_krustal) == (num_conexao - 1))
                    break;
          }
     }

     return custo_min;
}

int main(){

     string estacao_atual, est1, est2, inutil;

     //Auxiliares para armazenar em número as estações
     int est1_Conexao, est2_Conexao;
     int conexao_atual;

     //Custo mínimo final
     long long custo_min;

     //Validar o Krustal por meio da regra: V == N-1
     int valida_krustal;

     while(cin >> num_estacao >> num_conexao){
          if(num_estacao == 0 && num_conexao == 0){
               break;
          }

          //Iniciando variaveis
          EstacaoId.clear();
          ListaAdj.clear();
          custo_min = 0;
          iniciaConexao(num_estacao);

          //Leitura das Estações e atribuindo com Conexao
          for(int i = 0; i < num_estacao; i++){
               cin >> estacao_atual;
               EstacaoId[estacao_atual] = i;
          }
          //Leitura das Conexões e atribuindo na Lista
          for(int i = 0; i < num_conexao; i++){
               cin >> est1 >> est2 >> conexao_atual;
               est1_Conexao = EstacaoId[est1];
               est2_Conexao = EstacaoId[est2];

               ListaAdj.push_back(make_pair(conexao_atual, make_pair(est1_Conexao, est2_Conexao)));
          }
          cin >> inutil;

          custo_min = Kruskal(&valida_krustal);
          if (valida_krustal == (num_estacao - 1)){
               cout << custo_min << endl;
          }
          else{
               cout << "Impossible" << endl;
          }
     }

     return 0;
}