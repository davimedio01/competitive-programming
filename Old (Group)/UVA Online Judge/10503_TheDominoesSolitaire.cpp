/*

Resolvido com Backtracking:

1 - "Escolhas"
2 - "Restrições"
3 - "Objetivo"

Escolhas: 
Restrições: 
Objetivos: 

*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool validateDomino(pair<int, int> lastPiece, vector<int> solution)
{
     if (solution.back() != lastPiece.first)
     {
          return false;
     }

     return true;
}

int validatePiece(pair<int, int> piece, vector<int> solution)
{
     if (solution.back() == piece.first)
     {
          return 1;
     }
     else if (solution.back() == piece.second)
     {
          return 2;
     }

     return 0;
}

bool solveDomino(vector<pair<int, int>> *pieces, int n, int m,
                 int cont, pair<int, int> lastPiece, vector<int> *solution)
{
     if (cont == 0)
     {
          return validateDomino(lastPiece, *solution);
     }

     for (int i = 0; i < m; i++)
     {
          int aux = validatePiece((*pieces)[i], *solution);

          if (aux == 1)
          {
               (*solution).push_back((*pieces)[i].first);
               (*solution).push_back((*pieces)[i].second);

               int aux1, aux2;

               aux1 = (*pieces)[i].first;
               aux2 = (*pieces)[i].second;
               (*pieces)[i].first = -1;
               (*pieces)[i].second = -1;

               if (solveDomino(pieces, n, m, cont - 1, lastPiece, solution))
               {
                    return true;
               }

               (*pieces)[i].first = aux1;
               (*pieces)[i].second = aux2;

               (*solution).pop_back();
               (*solution).pop_back();
          }
          else if (aux == 2)
          {
               (*solution).push_back((*pieces)[i].second);
               (*solution).push_back((*pieces)[i].first);

               int aux1, aux2;

               aux1 = (*pieces)[i].first;
               aux2 = (*pieces)[i].second;
               (*pieces)[i].first = -1;
               (*pieces)[i].second = -1;

               if (solveDomino(pieces, n, m, cont - 1, lastPiece, solution))
               {
                    return true;
               }

               (*pieces)[i].first = aux1;
               (*pieces)[i].second = aux2;

               (*solution).pop_back();
               (*solution).pop_back();
          }
     }

     return false;
}

int main(){

     int n, m;

     while (cin >> n >> m && n != 0)
     {
          pair<int, int> firstPiece, lastPiece;

          cin >> firstPiece.first >> firstPiece.second;
          cin >> lastPiece.first >> lastPiece.second;

          vector<int> solution;

          solution.push_back(firstPiece.first);
          solution.push_back(firstPiece.second);

          vector<pair<int, int>> possiblePieces;

          for (int i = 0; i < m; i++)
          {
               int aux1, aux2;

               cin >> aux1 >> aux2;
               possiblePieces.push_back(make_pair(aux1, aux2));
          }

          if (solveDomino(&possiblePieces, n, m, n, lastPiece, &solution))
          {
               cout << "YES" << endl;
          }
          else
          {
               cout << "NO" << endl;
          }
     }

     return 0;
}