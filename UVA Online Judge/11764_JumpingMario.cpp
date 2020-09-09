#include <bits/stdc++.h>
#define MAX 50

using namespace std;

int main()
{
    int T;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int N;

        cin >> N;

        vector<int> w;

        for (int j = 0; j < N; j++)
        {
            int aux;

            cin >> aux;

            w.push_back(aux);
        }

        int l, h, cur;

        l = 0;
        h = 0;

        cur = w[0];

        for (int j = 1; j < N; j++)
        {
            if (cur < w[j])
            {
                h++;
            }
            else if (cur > w[j])
            {
                l++;
            }

            cur = w[j];
        }

        printf("Case %d: %d %d\n", i, h, l);
    }

    return 0;
}