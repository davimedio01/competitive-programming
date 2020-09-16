#include<bits/stdc++.h>

using namespace std;

int main(){
    long int n;

    cin >> n;

    vector<long long int> heights;

    for(long int i = 0; i < n; i++){
        long long int height;

        cin >> height;
        height &= 1;

        heights.push_back(height);
    }

    stack <long long int> aux;

    for(long int i = 0; i < n; i++){
        if(aux.empty() == 0 && heights[i] == aux.top()){
            aux.pop();
        }
        else{
            aux.push(heights[i]);
        }
    }

    if(aux.size() <= 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
