/*Criado por Davi Augusto - BCC - UNESP Bauru*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    long int num;
    cin >> num;

    deque<int> ada;
    //string comandos;
    int elemento;
    bool reverso = false;

    while(num--){

        //Ler comandos
        string comandos;
        cin >> comandos;

        //Condições de CADA Comando
        if(comandos == "toFront"){
            cin >> elemento;
            if (reverso == false){
                ada.push_front(elemento);
            }
            else{
                ada.push_back(elemento);
            }
            
        }
        else if(comandos == "push_back"){
            cin >> elemento;
            if(reverso == false){
                ada.push_back(elemento);
            }
            else{
                ada.push_front(elemento);
            }
            
        }
        else if (comandos == "reverse" && reverso == false)
        {
            reverso = true;
            //cout << endl << reverso << endl;
        }
        else if (comandos == "reverse" && reverso == true)
        {
            reverso = false;
            //cout << "\n" << reverso << endl;
        }

        //"Front"/"Back": printar e eliminar elemento
        if(comandos == "front"){
            //Verificando se o elemento existe
            if(ada.empty()){
                cout << "No job for Ada?" << endl;
            }
            else{
                //Caso seja reverso, printar o ultimo
                if (reverso == true){
                    cout << ada.back() << endl;
                    ada.pop_back();
                }
                else{
                    cout << ada.front() << endl;
                    ada.pop_front();
                }
            }
            
        }
        if(comandos == "back"){
            //Verificando se o elemento existe
            if (ada.empty())
            {
                cout << "No job for Ada?" << endl;
            }
            else
            {
                //Caso seja reverso, printar o primeiro
                if (reverso == true){
                    cout << ada.front() << endl;
                    ada.pop_front();
                }
                else{
                    cout << ada.back() << endl;
                    ada.pop_back();
                }
            }
        }

    }
    
    return 0;
}