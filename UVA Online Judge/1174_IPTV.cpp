//Criado por Davi Augusto

#include <bits/stdc++.h>

using namespace std;

#define MAX 50002

vector<int> links (MAX);
vector<pair<int, pair<int, int>>> p;

void inicializa(int cidadesConectadas)
{
     links.assign(cidadesConectadas, 0);
     for (int i = 0; i < cidadesConectadas; i++)
     {
          links[i] = i;
     }
}

int no(int x)
{
     while (links[x] != x)
     {
          links[x] = links[links[x]];
          x = links[x];
     }
     return x;
}

void uniao(int x, int y)
{
     int p = no(x);
     int q = no(y);
     links[p] = q;
}

long long kruskal(int linksExistentes)
{
     sort(p.begin(), p.end());

     int x, y;
     long long custo, custoMinimo = 0;

     int aux = 0;
     for (int i = 0; i < linksExistentes; i++)
     {
          // Seleciona as arestas, uma a uma, em ordem crescente desde o começo
          x = p[i].second.first;
          y = p[i].second.second;
          custo = p[i].first;

          // Verifica se as arestas selcionadas estão criando um ciclo ou não
          if (no(x) != no(y))
          {
               custoMinimo += custo;
               uniao(x, y);
               aux++;
               if (aux == linksExistentes - 1)
               {
                    break;
               }
          }
     }
     return custoMinimo;
}

int main()
{
     int casosTeste, cidadesConectadas, linksExistentes, pesosLinks, cont;
     long long custoMinimo;
     string cidade1, cidade2;
     map<string, int> ordem;

     cin >> casosTeste;
     //cin.ignore();

     while(casosTeste--)
     {
          
          //Com relação ao código genérico de Kruskal, as cidades conectadas são os vértices (nós)
          //E os links existentes são as arestas
          cin >> cidadesConectadas;
          cin >> linksExistentes;

          cont = 0;
          ordem.clear();
          links.clear();
          p.clear();

          inicializa(cidadesConectadas);

          for (int i = 0; i < linksExistentes; i++)
          {
               cin >> cidade1 >> cidade2 >> pesosLinks;
               if (ordem.count(cidade1) == 0)
               {
                    ordem[cidade1] = cont++;
               }
               if (ordem.count(cidade2) == 0)
               {
                    ordem[cidade2] = cont++;
               }

               p.push_back(make_pair(pesosLinks, make_pair(ordem[cidade1], ordem[cidade2])));
          }

          custoMinimo = kruskal(linksExistentes);

          cout << custoMinimo << endl;
          if(casosTeste > 0){
               cout << endl;
          }
     }
}
