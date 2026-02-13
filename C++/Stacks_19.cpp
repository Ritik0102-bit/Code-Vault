// Postfix Notation  -> Reverse Polish Notation

#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

int calc(int n1,int n2,char ch){
    if(ch=='^'){
        return pow(n1,n2);
    }
    if(ch=='/'){
        return n1/n2;
    }
    if(ch=='*'){
        return n1*n2;
    }
    if(ch=='+'){
        return n1+n2;
    }
    if(ch=='-'){
        return n1-n2;
    }
    return 0;
}

// Approach 1:
// when our string only contains single digit numbers
int Postfix_Notation(string s){
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else{
            int n1=st.top();
            st.pop();
            int n2=st.top();
            st.pop();
            st.push(calc(n2,n1,s[i]));
        }
    }
    return st.top();
}

// Approach 2:
// When our string contains multi-digit numbers
int Postfix_Notation_MultiDigit(string s) {
    stack<int> st;

    for (int i = 0; i < s.size(); i++) {
        
        // 1. Skip spaces
        if (s[i] == ' ') {
            continue;
        }

        // 2. If digit, extract the WHOLE number
        if (isdigit(s[i])) {
            int num = 0;
            
            // Keep reading digits until we hit a space or operator
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            // Because the while loop moves 'i' forward, we need to step back
            // one position so the main loop's i++ doesn't skip a character.
            i--; 
            
            st.push(num);
        }
        // 3. If operator
        else {
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            st.push(calc(n2, n1, s[i]));
        }
    }
    return st.top();
}

int main() {
    string s1 = "46+2/5*7+"; // Example: (4+6)/2*5+7 = 32
    cout << "Result: " << Postfix_Notation(s1) << endl;

    // Note: You MUST use spaces between numbers now
    string s2 = "100 20 + 5 /"; // (100 + 20) / 5 = 24
    cout << "Result: " << Postfix_Notation_MultiDigit(s2) << endl;
    
    return 0;
}