/**/

#include <bits/stdc++.h>

#define MAX_NODES 100

using namespace std;


int main(){

    int n, m, scenario = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }

        vector<vector<int>> dp(MAX_NODES + 1, vector<int>(MAX_NODES + 1, 0));

        for (int i = 0; i < m; i++)
        {
            int aux1, aux2, aux3;
            cin >> aux1 >> aux2 >> aux3;

            dp[aux1][aux2] = dp[aux2][aux1] = aux3;
        }

        int S, D, T;
        cin >> S >> D >> T;

        //Calculando por DP...
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j])); //k: interligação de cidades
                }
            }
        }

        dp[S][D]--;

        /*
        cout << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */

        cout << "Scenario #" << scenario << endl;
        scenario++;

        if((T % dp[S][D]) > 0){
            cout << "Minimum Number of Trips = " << (T)/(dp[S][D]) + 1 << endl;
        }
        else{
            cout << "Minimum Number of Trips = " << (T)/(dp[S][D]) << endl;
        }
        cout << endl;
    }
    
    return 0;
}