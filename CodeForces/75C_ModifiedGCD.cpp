/*
Para resolver o exercício, basta encontrar todos os fatores 
entre os dois números e armazená-los em um set como na função "SalvaFatores"

A partir disso, só procurar neste set o maior valor e retorná-lo
*/

#include <bits/stdc++.h>
#include <iostream>

#define MAX 1e9

using namespace std;

set<long long> fatores;

void SalvaFatores(long long n1, long long n2)
{
     long long gcd = __gcd(n1, n2);
     for (long long i = 1; i*i <= gcd; i++)
     {
          if (gcd % i == 0)
          {
               fatores.insert(i);
               fatores.insert(gcd/i);
          }
     }
}

long long ProcuraMaiorDivisor(long long low, long long high)
{
     long long aux = -1;
     for (auto i = fatores.begin(); i != fatores.end(); ++i)
     {
          if((*i) >= low && (*i) <= high)
          {
               aux = (*i);
          }
     }
     return aux;
}

int main(){

     long long num1, num2;
     cin >> num1 >> num2;

     SalvaFatores(num1, num2);

     long int casos;
     cin >> casos;

     long long low, high;
     for(long int i = 0; i < casos; i++)
     {
          cin >> low >> high;
          cout << ProcuraMaiorDivisor(low, high) << endl;
     }


     return 0;
}