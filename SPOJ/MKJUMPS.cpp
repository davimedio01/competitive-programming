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

#define MAX_MATRIX 10

using namespace std;

int solveBoard(vector<pair<int, int>> chessDisposition, int row, int col, int n, vector<vector<int>> *matrix, int maxSquares, int sum)
{
     if ((row < 0 || row >= n) || ((col < chessDisposition[row].first || col > chessDisposition[row].second)) || ((*matrix)[row][col] == 1))
     {
          return maxSquares;
     }
     if(sum > maxSquares){
          maxSquares = sum;
     }

     (*matrix)[row][col] = 1;
     maxSquares = solveBoard(chessDisposition, row - 2, col - 1, n, matrix, maxSquares, sum + 1);
     maxSquares = solveBoard(chessDisposition, row - 2, col + 1, n, matrix, maxSquares, sum + 1);
     maxSquares = solveBoard(chessDisposition, row - 1, col - 2, n, matrix, maxSquares, sum + 1);
     maxSquares = solveBoard(chessDisposition, row - 1, col + 2, n, matrix, maxSquares, sum + 1);
     maxSquares = solveBoard(chessDisposition, row + 1, col - 2, n, matrix, maxSquares, sum + 1);
     maxSquares = solveBoard(chessDisposition, row + 1, col + 2, n, matrix, maxSquares, sum + 1);
     maxSquares = solveBoard(chessDisposition, row + 2, col - 1, n, matrix, maxSquares, sum + 1);
     maxSquares = solveBoard(chessDisposition, row + 2, col + 1, n, matrix, maxSquares, sum + 1);
     (*matrix)[row][col] = 0;

     return maxSquares;
}

int main()
{

     int n, test = 0;

     while (cin >> n && n != 0)
     {
          test++;

          vector<pair<int, int>> chessDisposition;
          int squares;

          squares = 0;

          for (int i = 0; i < n; i++)
          {
               int first, second;

               cin >> first >> second;
               chessDisposition.push_back(make_pair(first, first + second - 1));

               squares += second;
          }

          vector<vector<int>> matrix(MAX_MATRIX, vector<int>(MAX_MATRIX, 0));
          int maxSquares = 0;

          squares -= solveBoard(chessDisposition, 0, chessDisposition[0].first, n, &matrix, 0, 1);

          if (squares == 1)
          {
               cout << "Case " << test << ", " << squares << " square can not be reached." << endl;
          }
          else
          {
               cout << "Case " << test << ", " << squares << " squares can not be reached." << endl;
          }
     }

     return 0;
}