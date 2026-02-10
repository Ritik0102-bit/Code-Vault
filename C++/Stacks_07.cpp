// Reverse Stack

// There are two approach to do this Problem

// 1st is iterative in which we use two temporary stack
// first we will copy elments from original stack to temp stack
// then temp to temp2
// then again from temp2 to our original stack

// 2nd Approach is Recursive
// In this we will push every element from call stack to the bottom of stack

#include<iostream>
#include<stack>

using namespace std;

// Iterative Approach
void reverse_stack(stack<int> &st){
    stack<int> temp,temp2;

    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    
    while(!temp.empty()){
        temp2.push(temp.top());
        temp.pop();
    }
    
    while(!temp2.empty()){
        st.push(temp2.top());
        temp2.pop();
    }
}

// Recursive Call Stack
void insert_at_Bottom(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int curr=st.top();
    st.pop();
    insert_at_Bottom(st,x);
    st.push(curr);
}

// Recursive Approach
void reverse_stack_2(stack<int> &st){
    if(st.empty()){
        return;
    }

    int curr=st.top();
    st.pop();

    reverse_stack_2(st);
    insert_at_Bottom(st,curr);
}

int main(){
    stack<int> st;

    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverse_stack(st);

    reverse_stack_2(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}