#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, X;

    cin >> N >> X;

    vector<int> viewPoints;

    for(int i = 0; i < N; i++){
        int aux;

        cin >> aux;

        viewPoints.push_back(aux);
    }

    int maxView, sum;

    maxView = 1;
    sum = 1;

    for(int i = 1; i < N; i++){
        if(viewPoints[i] - viewPoints[i - 1] <= X){
            sum++;
        }
        else{
            maxView = max(sum, maxView);
            sum = 1;
        }
    }

    maxView = max(sum, maxView);

    cout << maxView << endl;

    return 0;
}