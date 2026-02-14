// Some Inbuilt functions of string

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    string str="Hello";

    // Reverse function
    reverse(str.begin(),str.end()); // reverse(ptr1,ptr2)
    cout << str << endl;

    // Substring Function
    string str1="Algorithm"; 
    cout << str1.substr(0,2) << endl;  // str.substr(position,length)
    cout << str1.substr(1) << endl;  // If i don't provide length then it will print whole string from that position
    
    // Concatination (+)
    string str2="Hello";
    string str3="World";
    cout << str2+str3 << endl;
    // We can directly concatinate the strings with plus(+) operator But for character arrays we need strcat function

    char str4[20]="Hello";
    char str5[20]="World";
    strcat(str4,str5);
    cout << str4 << endl;

    // Pushback() function
    // this function insert a character at the end of the string
    string str6="children";
    str6.push_back('s');
    cout << str6 << endl ;

    // size()  &  length()
    cout << str6.size() << endl;
    cout << str6.length() << endl;

    // To find length of character array we use strlen()
    cout << strlen(str5) << endl;
    
    // to_string()  --> to convert numeric value to string
    int num=432;
    string str7=to_string(num);
    cout << str7 + "1" << endl;

    return 0;
}