#include <iostream>
#include <string>

#define max 100000

using namespace std;

int main()
{

    long long int tam_string;
    cin >> tam_string;
    string binario;
    cin >> binario;

    int one = 0, zero = 0;
    for (int i = 0; i < tam_string; i++)
    {

        //Analise dos char's 'z' (zero) e 'n' (one)
        if (binario[i] == 'z')
            zero++;
        if (binario[i] == 'n')
            one++;
    }
    //Sa?da: 1
    while (one > 0)
    {
        cout << "1 ";
        one--;
    }
    //Sa?da: 0
    while (zero > 0)
    {
        cout << "0 ";
        zero--;
    }
    cout << endl;
    return 0;
}