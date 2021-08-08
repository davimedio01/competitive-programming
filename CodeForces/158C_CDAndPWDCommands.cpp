/*Criado por Davi Augusto - BCC - UNESP Bauru*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*cd: mudar o diretório
pwd: mostrar o diretório atual

- começa em "/" (root)
- ".." volta um diretório (se n estiver no root)

*/


int main(){

    int n;
    cin >> n;

    //Uso do conceito de "Pilha"
    vector<string> final;

    while(n--){
        //Auxiliares
        string comando, aux, tok;
        cin >> comando;

        if(comando == "pwd"){
            //Printar a barra inicial de saída
            cout << '/';
            //Printar o vector
            for(int i=0; i<final.size(); i++){
                cout << final[i] << "/";
            }
            cout << endl;
        }
        if(comando == "cd"){
            cin >> aux;

            //Caso começar com barra, basta limpar o vetor (pós-root)
            if(aux[0] == '/')
                final.clear();
            
            //Analisando o comando digitado
            for(int i=0; i<aux.length(); i++){
                //Caso tenha digitado ".."
                if(aux[i] == '.' && aux[i+1] == '.'){
                    if(final.size() > 0)
                        final.pop_back(); //Caso o vetor final já contenha elementos, ele remove o ultimo diretorio
                    i++;
                }
                else if(aux[i] == '/'){
                    //Caso encontre uma barra, o "tok" (token) abaixo é armazenado em uma posição do vector
                    if(tok.length() > 0)
                        final.push_back(tok);
                    
                    tok.clear(); //E limpado ao final do processo (por ser um token separador)
                }
                else
                {
                    tok.push_back(aux[i]); //Armazenando o diretório no token
                }
            }
            //Ultima posição do Token (Acrescentar ao vector e limpar o token)
            if(tok.length() > 0)
            {
                final.push_back(tok);
                tok.clear();
            }
        }
    }

    return 0;
}