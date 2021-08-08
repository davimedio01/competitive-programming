/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){

     int P, A, R, max, countPearls;
     string pearl, name;
     set<string> allPearls;
     map<string, int> studentPearls;
     multimap<int, string> output;
     set<string> results;

     while(cin >> P >> A >> R && (P != 0 && R != 0 && A != 0)){
          cin.ignore();

          for(int i = 0; i < P; i++){
               getline(cin, pearl);

               allPearls.insert(pearl);
          }

          output.clear();
          max = 0;

          for(int i = 0; i < A; i++){            
               countPearls = 0;
               studentPearls.clear();

               getline(cin, name);

               for(int j = 0; j < R; j++){
                    getline(cin, pearl);

                    if(allPearls.count(pearl) == 1 && studentPearls.count(pearl) == 0){
                         studentPearls[pearl] = 1;
                         countPearls++;
                    }
               }

               if(countPearls > max) max = countPearls;

               output.insert({countPearls, name});
          }

          results.clear();
          pair<multimap<int, string>::iterator, multimap<int, string>::iterator> search = output.equal_range(max);

          for(multimap<int, string>::iterator itr = search.first; itr != search.second; itr++){
               results.insert(itr->second);
          }
     
          for(set<string>::iterator itr = results.begin(); itr != results.end(); itr++){
               if(itr != results.begin()) cout << ", ";
               cout << *itr;
          }

          cout << endl;
     }

     return 0;
}