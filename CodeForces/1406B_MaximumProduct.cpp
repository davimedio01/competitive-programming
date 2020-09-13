/*
Author: Davi Augusto Neves Leite
Date: 12/09/2020
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

//Pega os maiores e é isso
ll maximumProduct(vector<ll> numbers, int n){
    int length = numbers.size() - 1;
    sort(numbers.begin(), numbers.end());

    return max(max(numbers[0] * numbers[1] * numbers[2] * numbers[3] * numbers[length],
                    numbers[0] * numbers[1] * numbers[length - 2] * numbers[length - 1] * numbers[length]),
                numbers[length - 4] * numbers[length - 3] * numbers[length - 2] * numbers[length - 1] * numbers[length]);
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

        vector<ll> numbers;

        for(int i = 0; i < n; i++){
            ll element;
            cin >> element;

            numbers.push_back(element);
        }
        
        /*
        ll answer = LONG_LONG_MIN;

        //Utilização de Permutação até encontrar o maior
        do{
            ll aux = 1LL;
            for(int i = 0; i < 5; i++){
                aux *= numbers[i];
            }

            //Analisando se é a maior multiplicação
            if(answer < aux){
                answer = aux;
            }
        }while(next_permutation(numbers.begin(), numbers.end()));
    
        cout << answer << endl;
        */

        cout << maximumProduct(numbers, n) << endl;
    }
    
    return 0;
}
