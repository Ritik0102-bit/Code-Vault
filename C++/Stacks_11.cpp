// 🎯 Problem: Previous Greater Element

// Given an array of integers, your task is to find the "Previous Greater Element" for each element in the array.

// The "Previous Greater Element" for an element x is the first element to its left in the array that is strictly greater than x.

// If no such element exists (i.e., all elements to the left are smaller or equal, or it's the first element), the Previous Greater Element is considered to be -1.

// Input Array: [ 4, 3, 9, 1, 6, 8, 2 ]
// Output Output: [1  4  1  9  9  9  8 ]

// To find PGE we first reverse the array & then do what we have done to find NGE

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> PGE(vector<int> v){
    vector<int> res(v.size(),1);
    stack<int> st;

    reverse(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[st.top()]<v[i]){
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
    💡 A Better Approach (Without Reversing)
    -------------------------------------------------------
    
    WHY THIS APPROACH?
    While the reverse trick works, it is slower because reversing 
    takes extra time O(N) and modifies the array. It is much more 
    standard to iterate from Left to Right and maintain the 
    stack logic for "Previous".

    COMPLEXITY:
    - Time: O(N)
    - Space: O(N)

    ALGORITHM:
    1. Iterate i from 0 to n.
    2. Remove elements from the stack that are smaller or equal 
       to v[i] (because they can't be the "Previous Greater" 
       if v[i] is strictly larger and blocks them).
    3. If the stack is not empty, the top element is the answer.
    4. Push v[i] to the stack.
*/

vector<int> PGE_Optimized(vector<int> v) {
    vector<int> res(v.size(), -1);
    stack<int> st; // We can store values directly for simpler PGE code

    for (int i = 0; i < v.size(); i++) {
        // Pop elements that are smaller or equal to current
        while (!st.empty() && st.top() <= v[i]) {
            st.pop();
        }
        
        // If stack has items, the top is the Previous Greater
        if (!st.empty()) {
            res[i] = st.top();
        }
        
        // Push current value
        st.push(v[i]);
    }
    return res;
}

int main(){
    vector<int> v={4, 3, 9, 1, 6, 8, 2 };

    vector<int> result=PGE(v);

    for(int i=0;i<result.size();i++){
        cout << result[i] << "  ";
    }

    return 0;
}