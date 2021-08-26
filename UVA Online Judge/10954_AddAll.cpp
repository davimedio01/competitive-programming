/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int findMinCost(int n, priority_queue<int> numberSet)
{
     int sum, cost = 0;

     while (n != 1)
     {
          sum = -numberSet.top();
          numberSet.pop();

          sum += -numberSet.top();
          numberSet.pop();

          cost += sum;
          numberSet.push(-sum);

          n--;
     }

     return cost;
}

int main(){

     int N, number;

     cin >> N;

     while (N != 0)
     {
          priority_queue<int> numberSet;

          for (int i = 0; i < N; i++)
          {
               cin >> number;

               numberSet.push(-number);
          }

          cout << findMinCost(N, numberSet) << endl;

          cin >> N;
     }

     return 0;
}