// In this code we are going to make a function for removing all occurences of 'a' from a string using recursion

#include<iostream>

using namespace std;

string remove_occurences(string &s,int idx, int n){
    if(idx==n){
        return "";
    }
    string curr="";
    curr=s[idx];
    return ((s[idx]=='a')?"":curr) + remove_occurences(s,idx+1,n);
}

int main(){
    string str="abcax";
    cout << remove_occurences(str,0,str.size());
}