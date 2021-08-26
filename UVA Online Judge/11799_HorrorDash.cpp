#include <iostream>

using namespace std;

int main(){

    int num_casos;
    cin >> num_casos;

    int num_estudante;
    int vel_est, vel_minpalhaco;
    int casos = 0;

    while(num_casos > 0){

        cin >> num_estudante;
        vel_minpalhaco = 0;
        for(int i=0; i<num_estudante; i++){
            cin >> vel_est;

            if(vel_est > vel_minpalhaco)
                vel_minpalhaco = vel_est; 
        }
        cout << "Case " << ++casos << ": " << vel_minpalhaco << endl;
        num_casos--;
    }
    
    return 0;
}