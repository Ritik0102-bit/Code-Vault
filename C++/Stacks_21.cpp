// Evaluation of Infix Notation

#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

// Function to find precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^' ) return 3;
    return 0;
}

// Function to perform arithmetic operations
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

int Infix_Notation(string tokens) {
    stack<int> values; // Stack for numbers
    stack<char> ops;   // Stack for operators

    for (int i = 0; i < tokens.length(); i++) {
        // 1. Skip spaces
        if (tokens[i] == ' ') continue;

        // 2. If it's a number, parse the full number
        if (isdigit(tokens[i])) {
            int val = 0;
            // Handle multi-digit numbers
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--; // Adjust index because the loop increments it
        }
        // 3. If it's an opening brace, push to ops
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }
        // 4. If it's a closing brace, solve entire brace
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(calc(val1, val2, op));
            }
            if (!ops.empty()) ops.pop(); // Pop the '('
        }
        // 5. If it's an operator
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(calc(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }

    // 6. Apply remaining operators
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(calc(val1, val2, op));
    }

    return values.top();
}

int main() {
    string expression = "( 10 + ( 20 * ( 6 - 1 ^ 23 ) ) / 100 ) * 2";
    cout << "Result: " << Infix_Notation(expression) << endl; // Output: 22
    return 0;
}