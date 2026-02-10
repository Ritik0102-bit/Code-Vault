// Insert an element At an Index of a Stack

#include<iostream>
#include<stack>

using namespace std;

// Approach 1 : Interative
void insert_at_idx(stack<int> &st,int x,int idx){
    stack<int> temp;
    while(st.size()!=idx-1){
        int curr=st.top();
        st.pop();
        temp.push(curr);
    }

    st.push(x);

    while(!temp.empty()){
        int curr=temp.top();
        temp.pop();
        st.push(curr);
    }
}

// Approach 2 : Recursive Call Stack
void insert_at_idx_2(stack<int> &st,int x,int idx){
    if(st.size()==idx-1){
        st.push(x);
        return;
    }

    int curr=st.top();
    st.pop();
    insert_at_idx_2(st,x,idx);
    st.push(curr);
}

int main(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    insert_at_idx(st,100,2);
    insert_at_idx_2(st,0,5);

    while(!st.empty()){
        cout << st.top() << "  ";
        st.pop();
    }
}