// Insert an element At Bottom of a Stack

#include<iostream>
#include<stack>

using namespace std;

// Approach 1 : Interative
void insert_at_Bottom(stack<int> &st,int x){
    stack<int> temp;
    while(!st.empty()){
        int curr=st.top();
        temp.push(curr);
        st.pop();
    }

    st.push(x);

    while(!temp.empty()){
        int curr=temp.top();
        st.push(curr);
        temp.pop();
    }
}

// Approach 2 : Recursive Call Stack
void insert_at_Bottom_2(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int curr=st.top();
    st.pop();
    insert_at_Bottom_2(st,x);
    st.push(curr);
}

int main(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    insert_at_Bottom(st,0);

    insert_at_Bottom_2(st,-1);

    while(!st.empty()){
        cout << st.top() << "  ";
        st.pop();
    }

    return 0;
}