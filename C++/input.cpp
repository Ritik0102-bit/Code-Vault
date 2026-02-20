#include<iostream>
#include<string>

using namespace std;

int main(){
    string user_tea;
    int tea_quantity;
    cout << "What would you like to order in tea?" << endl;
    getline(cin,user_tea);

    // ask for quantity

    cout << "How many cups of " << user_tea << " Would you like to have?" << endl;
    cin >> tea_quantity;

    cout << tea_quantity << endl;
    cout << user_tea;
    return 0;
}