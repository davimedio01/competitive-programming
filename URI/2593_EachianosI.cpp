/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     multimap<string, int> positions;
     string text, word;
     char letter;
     int M, pos = 0;

     while (scanf("%c", &letter) && letter != '\n')
     {
          if (letter != ' ')
          {
               text.push_back(letter);
          }
          else
          {
               positions.insert({text, pos});
               pos += text.length() + 1;

               text.clear();
          }
     }

     positions.insert({text, pos});

     cin >> M;

     pair<multimap<string, int>::iterator, multimap<string, int>::iterator> search;
     multimap<string, int>::iterator itr;

     for (int i = 0; i < M; i++)
     {
          cin >> word;

          search = positions.equal_range(word);

          if (search.first == search.second)
          {
               cout << "-1";
          }
          else
          {
               for (itr = search.first; itr != search.second; itr++)
               {
                    if (itr != search.first && itr != search.second)
                         cout << " ";
                    cout << itr->second;
               }
          }

          cout << endl;
     }

     return 0;
}