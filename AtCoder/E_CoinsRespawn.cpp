#include <bits/stdc++.h>

using namespace std;

int N, M, P;
vector<tuple<int, int, long long>> grafo;
long long resp;

void BellmanFord(int inicio)
{
     vector<long long> distancia(N + 1, LONG_LONG_MAX);
     distancia[inicio] = 0;

     //Verifica o looping negativo (não há máximo)
     vector<bool> verifica(N + 1, false);
     verifica[N] = true;

     int primeiro, segundo;
     long long moedas;

     //Verifica o máximo possível, exceto os casos de looping negativo
     for (int i = 1; i < N; i++)
     {
          for (int j = 0; j < M; j++)
          {
               tie(primeiro, segundo, moedas) = grafo[j];

               if (distancia[primeiro] != LONG_LONG_MAX &&
                   distancia[primeiro] + moedas < distancia[segundo])
               {
                    distancia[segundo] = distancia[primeiro] + moedas;
               }

               //Salvando o vértice percorrido
               if(verifica[segundo] == true)
               {
                    verifica[primeiro] = true;
               }
          }
     }

     //Salvando a resposta máxima atual
     resp = max((long long)0, -distancia[N]);

     //Percorrendo o grafo e verificando se há o looping negativo
     for(int i = 0; i < M; i++)
     {
          tie(primeiro, segundo, moedas) = grafo[i];

          if (distancia[primeiro] != LONG_LONG_MAX &&
              distancia[primeiro] + moedas < distancia[segundo] &&
              verifica[segundo] == true)
          {
               //Looping negativo = impossível
               resp = -1;
               break;
          }     
     }
     

}

int main()
{
     cin >> N >> M >> P;

     for (int i = 0; i < M; i++)
     {
          int primeiro, segundo;
          long long moedas;
          cin >> primeiro >> segundo >> moedas;

          grafo.push_back({primeiro, segundo, P - moedas});
     }

     BellmanFord(1);
     cout << resp << endl;

     return 0;
}