// Given two strings s and t, determine if they are isomorphic.

// Input: s = "egg", t = "add"
// Output: yes

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool is_isomorphic(string s1,string s2){
    vector<int> v1(128,-1);
    vector<int> v2(128,-1);

    if(s1.size()!=s2.size()){
        return false;
    }

    for(int i=0;i<s1.size();i++){
        // Checking whether the value in both vectors is same or not
        if(v1[s1[i]]!=v2[s2[i]]){
            return false;
        }
        // Storing the index in both vectors for mapping of these two characters
        v1[s1[i]]=v2[s2[i]]=i;
    }

    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    if(is_isomorphic(s1,s2)){
        cout << "They are Isomorphic";
    }
    else{
        cout << "They are not Isomorphic";
    }

    return 0;
}