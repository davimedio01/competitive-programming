/*
Author: Davi Augusto Neves Leite
Date: 12/09/2020
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int findMinimunSet(set<int> mex, int n){
    int cont = 0, answer = 0;
    bool flag = false;

    for(auto i = mex.begin(); i != mex.end(); i++){
        if((*i) != cont){
            answer += cont;
            flag = true;

            break;
        }
        cont++;
    }

    if(flag == false){
        answer += cont;
    }

    return answer;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        set<int, less<int>> A, B;
        
        for(int i = 0; i < n; i++){
            int element;
            cin >> element;

            //Caso o elemento já esteja em um set, colocar no outro
            if (A.count(element) == 0){
                A.insert(element);
            }
            else{
                B.insert(element);
            }
        }

        //Pegar o menor número possível de cada um dos set's e somar
        cout << findMinimunSet(A, n) + findMinimunSet(B, n) << endl;
    }
    
    return 0;
}