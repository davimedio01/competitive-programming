#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        
        cin >> n;

        vector<int> array;
        int even, odd;

        even = 0;
        odd = 0;

        for(int j = 0; j < n; j++){
            int number;

            cin >> number;

            if(number % 2 == 0){
                even++;
            }
            else{
                odd++;
            }

            array.push_back(number);
        }

        if(even % 2 != odd % 2){
            cout << "NO" << endl;

            continue;
        }
        else if(even % 2 == 0){
            cout << "YES" << endl;

            continue;
        }

        bool flag;

        flag = false;

        for(int j = 0; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(array[j] % 2 != array[k] % 2 && abs(array[j] - array[k]) == 1){
                    cout << "YES" << endl;

                    flag = true;
                    break;
                }
            }

            if (flag){
                break;
            }
        }

        if(!flag){
            cout << "NO" << endl;
        }
    }

    return 0;
}