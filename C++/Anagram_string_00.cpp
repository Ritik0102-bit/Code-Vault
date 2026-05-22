// Check whether two Strings are anagram of each other. Return true if they are else return false. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are an anagram of each other.

// Input 1: triangle integral

// Output 1: True

// Input 2: anagram grams

// Output 2: False

// Solution: https://pastebin.com/E5MPWvYd

#include<iostream>
#include<unordered_map>

using namespace std;

bool Is_Anagram(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }

    unordered_map<char,int> m;

    for(int i=0;i<s1.length();i++){
        m[s1[i]]++;
    }

    for(int i=0;i<s2.length();i++){
        if(m.find(s2[i])==m.end()){
            return false;
        }
        else{
            m[s2[i]]--;
        }
    }

    for(auto ele:m){
        if(ele.second!=0){
            return false;
        }
    }

    return true;
}

int main(){
    string s1="anagram";
    string s2="grams";

    cout << (Is_Anagram(s1,s2) ? "Is Anagram" : "Is Not Anagram");

    return 0;
}