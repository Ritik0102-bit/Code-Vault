// Stacks Implementation Using Array

// Push -> used to insert element at top
// Pop -> used to remove element from top
// size -> used to check no. of element in stack
// Peek -> used to see element from top
// is_full -> used to check whether the stack is full or not
// is_empty -> used to check whether the stack is empty or not

#include<iostream>

using namespace std;

class stack{
    int capacity;
    int* arr;
    int top;

    public:
    stack(int c){
        this->capacity=c;
        this->arr=new int[c];
        this->top=-1;
    }

    void push(int data){
        if(this->top==this->capacity-1){
            cout << "Stack OverFlow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top]=data;
    }

    int pop(){
        if(this->top==-1){
            cout << "Stack Underflow" << endl;
            return INT8_MIN;
        }
        return this->arr[this->top--];
    }
    
    int peek(){
        if(this->top==-1){
            cout << "Stack Underflow" << endl;
            return INT8_MIN;
        }
        return this->arr[this->top];
    }

    bool is_empty(){
        return this->top==-1;
    }

    bool is_full(){
        return this->top==this->capacity-1;
    }

    int size(){
        return this->top+1;
    }
};

int main(){
    stack st(10);
    cout << st.is_empty() << endl;
    cout << st.is_full() << endl;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.pop() << endl;

    cout << st.peek() << endl;

    cout << st.size() << endl;

    return 0;
}