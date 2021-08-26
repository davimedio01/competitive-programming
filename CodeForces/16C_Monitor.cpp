/*
1) Necessário encontrar o mínimo entre a nova proporção do display
2) Com isso, deve-se encontrar o novo "fator" mínimo (divisão entre o tamanho original e o aspect ratio)

Fórmula Base (http://screen-size.info/):

fator = a/x; -> height = y * fator
fator = b/y; -> width = x * fator

*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long gcd(long long x, long long y)
{
     if (y == 0)
     {
          return x;
     }

     return gcd(y, x % y);
}

int main(){

     //Problema de Proporção
     long long a, b, x, y;
     cin >> a >> b >> x >> y;

     ////////////////////////
     //Para casos específicos (minha análise)
     long long minimo;
     minimo = gcd(x, y);

     x /= minimo;
     y /= minimo;
     ////////////////////////

     //Retrata o menor fator (fórmula acima) para encontrar a nova altura e largura (máx area)
     long long fator = min(a/x, b/y);

     long long altura, largura;
     altura = x * fator;
     largura = y * fator;

     cout << altura << " " << largura << endl;
     
     return 0;
}