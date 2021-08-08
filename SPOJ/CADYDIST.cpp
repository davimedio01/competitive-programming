#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    long int num_classes, aux;
    long long int soma = 0;

    do{
        vector<long int> num_alunos, preco_doce;
        cin >> num_classes;
        if (!num_classes)
            break;
        for (long int i = 0; i < num_classes; i++){
            cin >> aux;
            num_alunos.push_back(aux);
        }
        sort(num_alunos.begin(), num_alunos.end());
        for (long int i = 0; i < num_classes; i++){
            cin >> aux;
            preco_doce.push_back(aux);
        }
        sort(preco_doce.begin(), preco_doce.end());
        reverse(preco_doce.begin(), preco_doce.end());

        soma = 0;
        for (long int i = 0; i < num_classes; i++) {
            soma += (num_alunos[i] * preco_doce[i]);
        }
        cout << soma << endl;

    } while (num_classes != 0);

    return 0;
}