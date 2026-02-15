// Given an array of strings. Write a program to find the longest common prefix string amongst an array of strings.

// Input: arr = ["flower", "flight", "flask"]
// Output: "fl"

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string longest_prefix(vector<string> &str){

    // Sort the array of strings
    sort(str.begin(),str.end());

    // then we will compare first & last strings to get our longest common prefix

    string ans="";

    string s1=str[0];
    string s2=str[str.size()-1];
    int i=0;
    int j=0;

    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            ans+=s1[i];
            i++;
            j++;
        }
        else{
            break;
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string> str(n);

    for(int i=0;i<n;i++){
        cin>>str[i];
    }

    cout << longest_prefix(str);
}