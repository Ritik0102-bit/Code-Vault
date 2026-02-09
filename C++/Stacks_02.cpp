// Stack Using STL

// In STL stack is crested by Deque

#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> st;

    // Insert elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    // Printing the size of stack 
    cout << st.size() << endl;
    
    // Printing a element from top
    cout << st.top() << endl; 

    // Remove a element from top
    st.pop();

    // Printing The Stack
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}