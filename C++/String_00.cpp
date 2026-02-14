#include<iostream>

using namespace std;

int main(){
    // 2 ways of declaring string
    string str1="Hello"; //1st way
    string str2("World");  //2nd way

    cout << str1 << " " << str2 << endl;

    string str3;
    cin >> str3; // used only for single word inputs
    
    string str4;
    getline(cin,str4); // used for many words input (sentence)
    cout << str3 << endl;
    cout << str4 << endl;

    // ASCII Value
    char ch;

    ch='A';
    cout << int(ch) << endl; //65

    ch='Z';
    cout << int(ch) << endl; //90
    
    ch='a';
    cout << int(ch) << endl; //97
    
    ch='z';
    cout << int(ch) << endl; //122
}