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

#define MAX 10

using namespace std;

bool solve(int pos, vector<long int> seq, vector<int> numbers,
           long int sum, long int K, vector<int> *result)
{
     if (pos == MAX)
     {
          return sum <= K;
     }

     for (int i = 0; i < MAX; i++)
     {
          result->push_back(numbers[i]);
          int aux = numbers[i];

          if (aux != -1 && aux * seq[pos] + sum <= K)
          {
               numbers[i] = -1;

               if (solve(pos + 1, seq, numbers, sum + aux * seq[pos], K, &(*result)))
               {
                    return true;
               }
          }

          result->pop_back();
          numbers[i] = aux;
     }

     return false;
}

int main(){

     int T, i;
     long int element, K;
     vector<int> numbers, result;
     vector<long int> seq;

     for (i = 0; i < MAX; i++)
     {
          numbers.push_back(i);
     }

     cin >> T;

     while (T--)
     {
          seq.clear();
          result.clear();

          for (i = 0; i < MAX; i++)
          {
               cin >> element;
               seq.push_back(element);
          }

          cin >> K;

          if (solve(0, seq, numbers, 0, K, &result))
          {
               for (vector<int>::iterator itr = result.begin(); itr != result.end(); itr++)
               {
                    cout << *itr;
                    cout << (itr != result.end() - 1 ? " " : "\n");
               }
          }
          else
          {
               cout << "-1" << endl;
          }
     }

     return 0;
}