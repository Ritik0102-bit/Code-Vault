// Prefix Notation  -> Polish Notation

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
int Prefix_Notation(string s){
    stack<int> st;
    for(int i=s.size()-1;i>=0;i--){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else{
            int n1=st.top();
            st.pop();
            int n2=st.top();
            st.pop();
            st.push(calc(n1,n2,s[i]));
        }
    }
    return st.top();
}

// Approach 2:
// When our string contains multi-digit numbers
int Prefix_Notation_MultiDigit(string s) {
    stack<int> st;

    for (int i = s.size() - 1; i >= 0; i--) {
        
        // 1. Skip spaces
        if (s[i] == ' ') {
            continue;
        }

        // 2. If Operator
        if (!isdigit(s[i])) {
            int n1 = st.top(); st.pop(); // Left Operand
            int n2 = st.top(); st.pop(); // Right Operand
            st.push(calc(n1, n2, s[i]));
        }
        // 3. If Digit (Handle Multi-digit)
        else {
            int num = 0;
            int multiplier = 1; // 1s place, 10s place, 100s place...

            // Move LEFT collecting digits until space or operator
            // We stay inside bounds (i >= 0) and check for digit
            while (i >= 0 && isdigit(s[i])) {
                int digit = s[i] - '0';
                num = num + (digit * multiplier);
                multiplier *= 10;
                i--;
            }
            // Since the while loop decremented i one extra time past the number,
            // we must increment it back so the outer for-loop doesn't skip the next char.
            i++; 
            
            st.push(num);
        }
    }
    return st.top();
}

int main() {
    // Example: -+7*45+20 -> (7+(4*5))-(2+0) = 27 - 2 = 25
    string s = "-+7*45+20"; 
    cout << "Result: " << Prefix_Notation(s) << endl;

    // Expression: + 100 20  -> (100 + 20) = 120
    // Expression: - / 100 2 3 -> (100 / 2) - 3 = 47
    
    string s1 = "+ 100 20";
    string s2 = "- / 100 2 3";

    cout << "Result 1: " << Prefix_Notation_MultiDigit(s1) << endl;
    cout << "Result 2: " << Prefix_Notation_MultiDigit(s2) << endl;
    
    return 0;
}