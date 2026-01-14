// Given the head of a singly linked list, reverse the list, and print the reversed list.

// we will do this with the help of Recursion

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

void print_in_reverse_order(Node* head){

    // Recursion

    if(head==NULL){
        cout << "NULL";
        return;
    }
    print_in_reverse_order(head->next);
    cout << " <- " << head->val;
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);

    print_linked_list(linked_list);

    print_in_reverse_order(linked_list);
}