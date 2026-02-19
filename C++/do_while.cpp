#include <iostream>
#include <string>
using namespace std;
int main(){
    string response;
    
    do {
        cout << "Tea Served" << endl;
        cout << "Do you want more tea (yes/no): ";
        getline(cin, response);
    } while (response == "yes" || response == "Yes");
}