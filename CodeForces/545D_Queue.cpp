/*Criado por Davi Augusto - BCC - UNESP Bauru*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    int num, aux;
    cin >> num;
    vector<int> final;final.clear();

    for(int i=0; i<num; i++){
        cin >> aux;
        final.push_back(aux);
    }
    sort(final.begin(), final.end());

    int cont = 0, felizes = 0;
    for(int i=0; i<num; i++){
        if(cont <= final[i]){
            cont += final[i];
            felizes++;
        }
    }
    cout << felizes << endl;


    return 0;
}