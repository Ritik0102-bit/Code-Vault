// Balanced Bracket Sequence

// There are Two Problems of balanced bracket sequence :-

// 1st is when we Only have to balance 1 kind of brackets
// So the approach to solve this problem is just that we will create a counter = 0 , 
// when we have opening bracket we will increase the counter
// & when we have closing bracket we will decrease the counter
// And at the last if the counter is still 0 , then the sequence is Balanced


// 2nd is when we have more than one kind of brackets
// In this we will use a stack

// Time Complexity: O(n)

#include<iostream>
#include<stack>

using namespace std;

bool balanced_bracket(string s){
    stack<char> st;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        if(s[i]==')' && !st.empty() && st.top()=='('){
            st.pop();
        }
        if(s[i]=='}' && !st.empty() && st.top()=='{'){
            st.pop();
        }
        if(s[i]==']' && !st.empty() && st.top()=='['){
            st.pop();
        }
    }

    return st.empty();
}

int main(){
    
    string s="{[((([{}])))]}";

    cout << balanced_bracket(s);
}