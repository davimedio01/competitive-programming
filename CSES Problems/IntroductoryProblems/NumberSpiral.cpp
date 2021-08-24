/*
Author: Davi Augusto Neves Leite
Date: 12/09/2020
*/

#include <bits/stdc++.h>

#define MAX 1000000002
typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    
    int t;
    cin >> t;

    while(t--){
        ll x, y;
        cin >> y >> x;

        if(x > y){
            if(x % 2 != 0){
                cout << (x*x) - y + 1 << endl;
            }
            else{
                x--;
                cout << (x*x) + y << endl;
            }
        }
        else{
            if(y % 2 == 0){
                cout << (y*y) - x + 1 << endl;
            }
            else{
                y--;
                cout << (y*y) + x << endl;
            }
        }

    }
    
    return 0;
}

/*
Exemplos:

x > y:

    y = 2; x = 3 => 8 => 3*3 - 2 + 1 => (x*x) - y + 1
    y = 1; x = 2 => 2 => 1*1 + 1 => (x--*x--) + y

x <= y:

    y = 3; x = 2 => 6 => 2*2 + 2 => (y--*y--) + x
    y = 2; x = 1 => 4 => 2*2 - 1 + 1 => (y*y) - x + 1

*/