#include <bits/stdc++.h>

#define MAX 51

using namespace std;

vector<int> cortes;
int dp[MAX][MAX];

void init()
{
    memset(dp, -1, sizeof(dp));
    cortes.clear();
}

int dynamicProgramming(int a, int b)
{

    if (b - a == 1)
    {
        return 0;
    }

    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }

    int aux = 10000000;

    for (int i = a + 1; i < b; i++)
    {
        int val = (cortes[b] - cortes[a]) + (dynamicProgramming(a, i) + dynamicProgramming(i, b));
        aux = min(val, aux);
    }

    dp[a][b] = aux;

    return aux;
}

int main()
{

    int tamMadeira, numCortes, corte;

    while (cin >> tamMadeira)
    {

        if (tamMadeira == 0)
        {
            break;
        }

        init();

        cin >> numCortes;

        cortes.push_back(0);

        for (int i = 0; i < numCortes; i++)
        {
            cin >> corte;
            cortes.push_back(corte); //Armazena as posições dos cortes
        }

        cortes.push_back(tamMadeira);

        int valorMinimo = dynamicProgramming(0, numCortes + 1);

        cout << "The minimum cutting is " << valorMinimo << "." << endl;
    }

    return 0;
}