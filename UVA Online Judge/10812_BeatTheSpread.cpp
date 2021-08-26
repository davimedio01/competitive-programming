#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int num, soma, diferenca;
    cin >> num;

    for(int i=0; i<num; i++){

        cin >> soma >> diferenca;
        
        if(soma<diferenca || (soma + diferenca) % 2 != 0){
            cout << "impossible" << endl;
        }
        else{
            int x = (soma+diferenca)/2;
            int y = soma - x;

            cout << x << " " << y << endl;
        }
    }
    
    return 0;
}