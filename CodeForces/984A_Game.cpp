#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    vector<int> game;
    int n, aux;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> aux;
        game.push_back(aux);
    }
    sort(game.begin(), game.end());

    //Fórmula do Termo Central
    if(n%2 == 0){
        cout << game[(n/2)-1] << endl;
    }
    else{
        cout << game[(n/2)] << endl;
    } 
    
    return 0;
}