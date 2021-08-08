#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, a, maxLen, lastA;
    map<int, int> dp;
    vector<int> v, sol;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }       

    maxLen = lastA = 0;

    for(int i = 0; i < n; i++){
        dp[v[i]] = max(dp[v[i]], dp[v[i]-1]+1);

        if(dp[v[i]] > maxLen){
            maxLen = dp[v[i]];
            lastA = v[i];
        }
    }

    for(int i = n-1; i >= 0; i--){
        if(v[i] == lastA){
            sol.push_back(i);
            lastA--;
        }
    }

    cout << maxLen << endl;

    for(vector<int>::reverse_iterator itr = sol.rbegin(); itr != sol.rend(); itr++){
        cout << (*itr)+1 << (itr+1 == sol.rend() ? "\n" : " ");
    }

    return 0;
}