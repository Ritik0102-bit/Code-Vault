// 🎯 Problem: Next Greater Element
// Given an array of integers, your task is to find the "next greater element" for each element in the array.

// The "next greater element" for an element x is the first element to its right in the array that is strictly greater than x.

// If no such element exists (i.e., all elements to the right are smaller or equal, or it's the last element), the next greater element is considered to be -1.

// Input Array: [ 4, 3, 9, 1, 6, 8, 2 ]
// Output Array: [ 9, 9, -1, 6, 8, -1, -1 ]

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> NGE(vector<int> v){
    vector<int> res(v.size(),-1);
    stack<int> st;

    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[st.top()]<v[i]){
            res[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }

    return res;
}

int main(){
    vector<int> v={4, 3, 9, 1, 6, 8, 2 };

    vector<int> result=NGE(v);

    for(int i=0;i<result.size();i++){
        cout << result[i] << "  ";
    }

    return 0;
}