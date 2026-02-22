#include<iostream>
using namespace std;

int main(){
    int teacups;
    cout << "Enter the number of teacups to serve : ";
    cin >> teacups;

    while(teacups>0){
        cout << "Serving a cup of tea \n" << teacups-1 << " remaining " << endl;
        teacups--;
    }
    cout << "All teacups are served.";
    return 0;
}