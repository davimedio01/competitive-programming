#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<string> chat;
    map<string, int> amigo;

    int numMensagens;
    string nome;

    cin >> numMensagens;

    for (int i = 0; i < numMensagens; i++)
    {
        cin >> nome;
        chat.push(nome);
        amigo[nome] = 0;
    }

    for (int i = 0; i < numMensagens; i++)
    {
        string aux = chat.top();
        if (amigo[aux] == 0)
        {
            amigo[aux]++;
            cout << aux << endl;
        }
        chat.pop();
    }
}