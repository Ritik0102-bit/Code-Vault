#include <iostream>

using namespace std;

int totalChaiServed(int chai[], int size){
    int total = 0;
    for(int i = 0 ; i < size ; i++){
        total += chai[i];
    }
    return total;
}

int main(){
    int chaiServed[7] = {50, 60, 55, 70, 65, 80, 75};

    int total = totalChaiServed(chaiServed, 7);
    cout << "Total chai served: " << total << endl;
    cout << "Size of array: " << sizeof(chaiServed) / sizeof(chaiServed[0]) << endl;
    cout << "Size of array in bytes: " << sizeof(chaiServed) << endl;

    // for each loop
    for(int element:chaiServed){
        cout << element << endl;
    }
    return 0;
}