/**/

#include <bits/stdc++.h>
#include <iostream>
#include <ctype.h>
#include <set>

using namespace std;

int main(){

     set<string> dicionario;
     string texto;
     char caractere;

     while (scanf("%c", &caractere) != EOF)
     {
          if (toupper(caractere) >= 'A' && toupper(caractere) <= 'Z')
          {
               texto.push_back(tolower(caractere));
          }
          else
          {
               if (!texto.empty())
               {
                    dicionario.insert(texto);
               }

               texto.clear();
          }
     }

     set<string, less<string>>::iterator itr;
     for (itr = dicionario.begin(); itr != dicionario.end(); itr++)
     {
          cout << *itr << endl;
     }

     return 0;
}