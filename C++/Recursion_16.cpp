// In this code we are going to code about alphabets COMBINATION that a number can represent using recursion

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// Input: digits = "23" 
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

// PHONE KEYPAD

// 1: 00
// 2: abc
// 3: def
// 4: ghi
// 5: jkl
// 6: mno
// 7: pqrs
// 8: tuv
// 9: wxyz
// 0:(space)

#include<iostream>
#include<vector>

using namespace std;

void func(string &str, int i, string result, vector<string> &li, vector<string> &v) {
    if(i == str.size()) {
        li.push_back(result);
        return;
    }
    int digit = str[i] - '0';
    if(digit <= 1) {
        func(str, i+1, result, li, v);
        return;
    }
    for(int j = 0; j < v[digit].size(); j++) {
        func(str, i + 1, result + v[digit][j], li, v);
    }
    return;
}

int main() {
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str = "23";
    vector<string> li;
    func(str, 0, "", li, v);
    for(int i = 0; i < li.size(); i++) {
        cout<<li[i]<<" ";
    }
}