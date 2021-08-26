/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

     int t, countTrees;
     string specie;
     double percentage;
     map<string, int> speciesList;

     cin >> t;
     cin.ignore();
     getline(cin, specie);

     for (int countCase = 0; countCase < t; countCase++)
     {
          if (countCase != 0)
               cout << endl;

          speciesList.clear();
          countTrees = 0;

          while (getline(cin, specie) && specie.length() > 0)
          {
               if (speciesList.count(specie) == 0)
               {
                    speciesList.insert({specie, 1});
               }
               else
               {
                    speciesList[specie]++;
               }

               countTrees++;
          }

          for (map<string, int>::iterator itr = speciesList.begin(); itr != speciesList.end(); itr++)
          {
               percentage = ((double)(itr->second * 100) / countTrees);

               cout << itr->first << " ";
               cout << fixed << setprecision(4) << percentage << endl;
          }
     }

     return 0;
}