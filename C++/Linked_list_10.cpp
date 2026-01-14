// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

#include<iostream>

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


void insert_at_tail(Node* &head,int value){
    Node* new_node=new Node(value);

    if(head==NULL){
        head=new_node;
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new_node;
}

void print_linked_list(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout << temp->val << " -> ";
        temp=temp->next;
    }

    cout << "NULL" << endl;
}

Node* Reverse_k_elements(Node* &head,int k){
    Node* prevptr = NULL;
    Node* currptr = head;

    int counter = 0; //for counting first k nodes

    while(currptr!=NULL && counter<k) { //reversing first k nodes
        Node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        counter++;
    }

    //currptr will give us (k+1)th node
    if(currptr!=NULL) {
        Node* new_head = Reverse_k_elements(currptr,k); //recursive call
        head->next = new_head;
    }

    return prevptr; //prevptr will give the new_head of connected linked list
}


int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);

    print_linked_list(linked_list);

    linked_list=Reverse_k_elements(linked_list,2);

    print_linked_list(linked_list);
    
}