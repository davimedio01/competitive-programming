#include <bits/stdc++.h>
#define MAX_INTEREST 10

using namespace std;

int main(){
    long n;

    cin >> n;

    vector<long long> positiveAttraction (MAX_INTEREST + 1);
    vector<long long> negativeAttraction (MAX_INTEREST + 1);
    
    for(int i = 0; i < n; i++){
        int aux;

        cin >> aux;

        if(aux >= 0){
            positiveAttraction[aux]++;
        }
        else{
            negativeAttraction[abs(aux)]++;
        }
    }

    long long maxCouples;

    maxCouples = 0;

    for(int i = 1; i <= MAX_INTEREST; i++){
        maxCouples += positiveAttraction[i] * negativeAttraction[i];
    }

    for(int i = positiveAttraction[0] - 1; i > 0; i--){
        maxCouples += i;
    }

    cout << maxCouples << endl;

    return 0;
}
