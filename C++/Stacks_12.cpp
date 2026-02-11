// 🎯 Problem: Previous Smaller Element

// Given an array of integers, your task is to find the "Previous smaller Element" for each element in the array.

// The "Previous Smaller Element" for an element x is the first element to its left in the array that is strictly smaller than x.

// If no such element exists (i.e., all elements to the left are greater or equal, or it's the first element), the Previous smaller Element is considered to be -1.

// Input Array: [ 4, 3, 9, 1, 6, 8, 2 ]
// Output Output: [1  1  3  1  1  6  1 ]

// To find PSE we first reverse the array & then do what we have done to find NSE

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> PSE(vector<int> v){
    vector<int> res(v.size(),1);
    stack<int> st;

    reverse(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[st.top()]>v[i]){
            res[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }

    reverse(res.begin(),res.end());
    return res;
}

/*
    -------------------------------------------------------
    🚀 OPTIMIZATION: The Standard Way (No Reversing)
    -------------------------------------------------------

    Just like with PGE, you can solve this in a single pass from 
    Left to Right without reversing. This is generally preferred 
    in interviews because it uses less memory and time.

    LOGIC:
    1. Iterate from Left to Right.
    2. We want a Previous Smaller, so we keep a stack of "candidates".
    3. If we see a number in the stack that is Greater or Equal to 
       our current number, we remove it (pop). 
       
       WHY POP? 
       Because the current number is smaller and to the right, 
       so it "blocks" the larger number from ever being the closest 
       smaller value for future elements.

    4. The top of the stack is your answer.
*/

vector<int> PSE_Optimized(vector<int> v){
    vector<int> res(v.size(), -1);
    stack<int> st; // Stores actual values for simplicity

    for(int i = 0; i < v.size(); i++){
        // We want Previous SMALLER.
        // So if stack top is LARGER or EQUAL, it's useless. Pop it.
        while(!st.empty() && st.top() >= v[i]){
            st.pop();
        }
        
        // If stack is not empty, the top is the strictly smaller element to the left
        if(!st.empty()){
            res[i] = st.top();
        }
        
        // Push current element as a candidate for future numbers
        st.push(v[i]);
    }
    return res;
}

int main(){
    vector<int> v={4, 3, 9, 1, 6, 8, 2 };

    vector<int> result=PSE(v);

    for(int i=0;i<result.size();i++){
        cout << result[i] << "  ";
    }

    return 0;
}