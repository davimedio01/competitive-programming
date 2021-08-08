/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     int M, N, value, salary;
     string workFunction, description;
     map<string, int> dictionary;

     cin >> M >> N;

     for (int i = 0; i < M; i++)
     {
          cin >> workFunction >> value;

          dictionary[workFunction] = value;
     }

     for (int i = 0; i < N; i++)
     {
          salary = 0;

          while (cin >> description && description != ".")
          {
               if (dictionary.count(description) != 0)
               {
                    salary += dictionary[description];
               }
          }

          cout << salary << endl;
     }

     return 0;
}