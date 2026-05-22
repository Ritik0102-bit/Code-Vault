// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Handwritten note: rearranging letters of a word to get another word

// Constraints: String s and t will only contain lowercase alphabetical characters.

// Input 1: s = "anagram", t = "nagaram"
// Output 1: yes

// Input 2: s = "bank", t = "atm"
// Output 2: no

#include<iostream>
#include<string>

using namespace std;

bool is_anagram(string s1, string s2){
    // frequency array
    int freq[26]={0};

    if(s1.size()!=s2.size()){
        return false;
    }

    for(int i=0;i<s1.size();i++){
        freq[s1[i]-'a']++;
        freq[s2[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }

    return true;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;

    cout << is_anagram(s1,s2);
}