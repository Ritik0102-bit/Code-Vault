// Delete an element From Bottom & From some Index

#include<iostream>
#include<stack>

using namespace std;

// Iterative Approach
void delete_from_bottom(stack<int> &st){
    stack<int> temp;
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        temp.push(curr);
    }

    temp.pop();

    while(!temp.empty()){
        int curr=temp.top();
        temp.pop();
        st.push(curr);
    }
}


// Recursive Approach - 1
void delete_from_bottom_2(stack<int> &st){
    // Base Case: If stack is empty, nothing to do
    if(st.empty()){
        return;
    }

    // 1. Store the top element
    int curr=st.top();
    st.pop();
    
    if(st.empty()){
        // If it is empty, 'topElement' was the bottom one.
        // We return immediately without pushing it back.
        return;
    }
    
    // 3. Recurse: Go deeper
    delete_from_bottom_2(st);

    // 4. Backtrack: Push the stored element back onto the stack
    st.push(curr);
}

// Recursive Approach -2
void delete_from_bottom_3(stack<int> &st){
    if(st.size()==1){
        st.pop();
        return;
    }

    // 1. Store the top element
    int curr=st.top();
    st.pop();

    delete_from_bottom_3(st);

    st.push(curr);
}

// Iterative Approach
void delete_at_index(stack<int> &st,int idx){
    stack<int> temp;

    while(st.size()!=idx){
        temp.push(st.top());
        st.pop();
    }

    st.pop();

    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

// Recursive Approach
void delete_at_index_2(stack<int> &st,int idx){
    if(st.size()==idx){
        st.pop();
        return;
    }

    int curr=st.top();
    st.pop();

    delete_at_index_2(st,idx);

    st.push(curr);
}


int main(){
    stack<int> st;

    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);

    delete_from_bottom(st);
    delete_from_bottom_2(st);
    delete_from_bottom_3(st);

    delete_at_index(st,1);
    delete_at_index_2(st,4);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop(); 
    }
}