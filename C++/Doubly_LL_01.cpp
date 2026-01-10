// Given the head of Doubly Linked list , Reverse it

#include<iostream>

using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};


class Doubly_linked_list{
    public:
    Node* head;
    Node* tail;

    Doubly_linked_list(){
        head=NULL;
        tail=NULL;
    }

    void insert_at_last(int data){
        Node* new_node=new Node(data);

        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }

        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    }

    void print_Doubly_LL(){
        Node* temp=head;
        while(temp!=NULL){
            cout << temp->val << " -> ";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }

};

void reverseDll(Node* &head, Node* &tail) {

    Node* currPtr = head;
    while(currPtr) {
        Node* nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = nextPtr;
        currPtr = nextPtr;
    }
    
    //swapping head and tail pointers
    Node* newHead = tail;
    tail = head;
    head = newHead;
}


int main(){
    Doubly_linked_list Doubly_LL;

    Doubly_LL.insert_at_last(1);
    Doubly_LL.insert_at_last(2);
    Doubly_LL.insert_at_last(3);
    Doubly_LL.insert_at_last(4);
    Doubly_LL.insert_at_last(5);
    Doubly_LL.insert_at_last(6);
    Doubly_LL.insert_at_last(7);
    Doubly_LL.insert_at_last(8);

    Doubly_LL.print_Doubly_LL();
    
    reverseDll(Doubly_LL.head,Doubly_LL.tail);
    
    Doubly_LL.print_Doubly_LL();
}