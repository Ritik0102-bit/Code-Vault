// Copy Stack

// Copy contents of one stack to another in same order

// 1st Approach
// Its not the best Approach

// when we first try to copy from one stack to another , the order of elements will be reversed
// So to overcome this we copy our stack to temp stack & then again we will copy it to resultant stack

// #include<iostream>
// #include<stack>

// using namespace std;

// stack<int> copy_stack(stack<int> &st){

//     stack<int> temp;
//     while(!st.empty()){
//         int curr=st.top();
//         temp.push(curr);
//         st.pop();
//     }

//     stack<int> result;
//     while(!temp.empty()){
//         int curr=temp.top();
//         result.push(curr);
//         temp.pop();
//     }

//     return result;
// }

// int main(){
//     stack<int> st;

//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);

//     stack<int> result=copy_stack(st);

//     while(!result.empty()){
//         cout << result.top() << "  ";
//         result.pop();
//     }

//     return 0;
// }




// 1st Approach
// Its the best Approach Using Recursion Call Stack


#include<iostream>
#include<stack>

using namespace std;

void copy_stack(stack<int> &st,stack<int> &res){

    if(st.empty()){
        return;
    }
    int curr=st.top();
    st.pop();
    copy_stack(st,res);
    res.push(curr);
}

int main(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    stack<int> result;
    
    copy_stack(st,result);

    while(!result.empty()){
        cout << result.top() << "  ";
        result.pop();
    }

    return 0;
}
