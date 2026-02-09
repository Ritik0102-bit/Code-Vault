// Stacks Implementation Using Linked list

#include<iostream>
#include <climits>

using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};

class stack{
    int capacity;
    Node* head;
    int curr_size;

    public:
    stack(int c){
        this->capacity=c;
        this->curr_size=0;
        this->head=NULL;
    }

    void push(int data){
        if(this->curr_size==this->capacity){
            cout << "Stack OverFlow" << endl;
            return;
        }
        
        Node* new_node=new Node(data);
        new_node->next=this->head;
        this->head=new_node;
        this->curr_size++;
        return;
    }

    int pop(){
        if(this->head==NULL){
            cout << "Stack UnderFlow " << endl;
            return INT_MIN;
        }

        this->curr_size--;
        int value=head->val;
        Node* to_delete=this->head;
        this->head=this->head->next;
        delete to_delete;
        return value;
    }
    
    int peek(){
        if(this->head==NULL){
            cout << "Stack UnderFlow " << endl;
            return INT_MIN;
        }

        return this->head->val;
    }

    int size(){
        return curr_size;
    }

    bool is_empty(){
        return this->head==NULL;
    }

    bool is_full(){
        return this->curr_size==this->capacity;
    }
};

int main(){
    stack st(10);
    
    cout << st.size() << endl;

    cout << st.is_empty() << endl;
    cout << st.is_full() << endl;

    st.push(1);
    st.push(1);
    st.push(2);
    st.push(2);
    st.push(3);

    cout << st.pop() << endl;

    cout << st.size() << endl;

    return 0;
}