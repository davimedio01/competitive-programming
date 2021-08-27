/*
Author: Davi Augusto Neves Leite
Date: 27/08/2021

Compilar com os argumentos: -O2 -Wall -Wextra
Executar com os argumentos: < input.txt > output.txt
*/

#include <bits/stdc++.h>

#define MODULO 1000000007

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    map<string, bool> existSchool;//Mapear as escolas já existentes
    int countTeams = 0;

    while(N--){
        string school, team;
        cin >> school >> team;

        //Se a escola não existir, salva ela no mapeamento
        if(existSchool.count(school) == 0){
            existSchool.insert(make_pair(school, true));

            //E salva o time completo no ranking e aumenta o contador
            string teamRanking = school + " " + team;
            countTeams++;

            //Printando os 12 primeiros vencedores
            if(countTeams <= 12)
                cout << teamRanking << endl;
        }
    }

    return 0;
}