// Check whether two Strings are isomorphic of each other. Return true if they are else return false.

// Two strings are isomorphic of each other if there is a one-to-one mapping possible for every character of the first string to every character of second string and all occurrences of every character in first string maps to the same character in the second string.

// Input 1: aab xxy
// Output 1: True

// Input 2: abcdec viouog
// Output 2: False


#include<iostream>
#include<unordered_map>

using namespace std;

bool Are_Isomorphic(string s1,string s2){

    if(s1.length()!=s2.length()){
        return false;
    }

    unordered_map<char,char> m;
    // check one to many mapping from s1 -> s2
    for(int i=0;i<s1.size();i++){
        if(m.find(s1[i])!=m.end()){
            if(m[s1[i]]!=s2[i]){
                return false;
            }
        }
        else{
            m[s1[i]]=s2[i];
        }
    }
    
    m.clear();

    // check one to many mapping from s2 -> s1
    for(int i=0;i<s2.size();i++){
        if(m.find(s2[i])!=m.end()){
            if(m[s2[i]]!=s1[i]){
                return false;
            }
        }
        else{
            m[s2[i]]=s1[i];
        }
    }

    return true;
}

int main(){
    string s1="abcdec";
    string s2="viouog";

    cout << (Are_Isomorphic(s1,s2) ? "Are Isomorphic" : "Are Not Isomorphic");

    return 0;
}