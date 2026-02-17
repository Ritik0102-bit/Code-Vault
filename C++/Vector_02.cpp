#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v(5); // vector of size 5
    
    for(int i=0;i<5;i++){
        cin>> v[i];
    }

    // for loop
    for(int i=0;i<5;i++){
        cout << v[i] << " ";
    }
    cout << endl;

    v.insert(v.begin()+2,6);
    
    // for each loop
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    v.erase(v.end()-4);

    // while loop
    int index=0;
    while(index<v.size()){
        cout << v[index++] << " ";
    }
    cout << endl;

    return 0;
}