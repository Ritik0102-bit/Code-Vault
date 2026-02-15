// Given a strings str, sort the given string.

// Constraints: The string will contain only alphabetical characters from a-z.

// Input 1: "codingwallah"
// Output 1: "aacdghillnow"

// Input 2: "star"
// Output 2: "arst"

#include<iostream>
#include<string>

using namespace std;

void sort_string(string &str){
    int freq[26]={0};

    for(int i=0;i<str.size();i++){
        int index=str[i]-'a';
        freq[index]++;
    }

    int j=0;
    for(int i=0;i<26;i++){
        while(freq[i]--){
            str[j++]=i+'a';
        }
    }

    return;
}

int main(){
    string str;
    cin>>str;

    sort_string(str);

    cout << str ;

    return 0;
}