#include <iostream>

using namespace std;

int main(){
    
    //lamda function
    auto preparedChai = [](int cups){
        cout << "Preparing " << cups << " cups of tea" << endl;
    };

    preparedChai(4);
    
    return 0;
}