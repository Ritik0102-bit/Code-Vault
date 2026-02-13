// Find the minimum number of brackets that we need to remove to make the given bracket sequence balanced.

#include<iostream>
#include<stack>

using namespace std;

int remove_bracket(string s){
    int c=0;
    stack<char> st;

    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                c++;
            }
        }
    }

    return c + st.size();
}

int main(){
    string s="()(()(((";

    cout << remove_bracket(s);
}