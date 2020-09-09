/**/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long int llint;

llint factDivCut(int x, int y);
llint factorial(int x);

int main(){
    //constants
    const int MAX_BUGS = 5;
    const int MAX_FEATURES = 3;
    
    //var
    int n;
    llint bugs, features, total;

    cin >> n;

    bugs = factDivCut(MAX_BUGS+n-1, n-1)/factorial(MAX_BUGS);
    features = factDivCut(MAX_FEATURES+n-1, n-1)/factorial(MAX_FEATURES);

    total = bugs*features;

    cout << total << endl;

    return 0;
}

llint factDivCut(int x, int y){
    llint f = 1;
    
    for(int i = x; i > y; i--){
        f *= i;
    }

    return f;
}

llint factorial(int x){
    llint f = 1;

    for(int i = x; i > 0; i--){
        f *= i;
    }

    return f;
}