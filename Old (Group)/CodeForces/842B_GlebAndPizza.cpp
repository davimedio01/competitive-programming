#include <bits/stdc++.h>
#define MAX 50

using namespace std;

int main()
{
    int r, d, N;

    cin >> r >> d >> N;

    int sol = 0;

    for (int i = 0; i < N; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        int aux = pow(a, 2) + pow(b, 2);

        if (aux <= pow(r - c, 2) && aux >= pow(r - d + c, 2))
        {
            sol++;
        }
    }

    cout << sol << endl;

    return 0;
}