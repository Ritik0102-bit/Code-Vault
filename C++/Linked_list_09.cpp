// Given the head of a singly linked list, reverse the list, and return the reversed list.

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

Node* Reverse_linked_list(Node* &head){
    Node* prev_ptr=NULL;
    Node* curr_ptr=head;
    Node* next_ptr;

    // curr_ptr->next=prev_ptr
    // Move all 3 ptr by one step ahead

    while(curr_ptr!=NULL){
        next_ptr=curr_ptr->next;
        curr_ptr->next=prev_ptr;
        prev_ptr=curr_ptr;
        curr_ptr=next_ptr;
    }

    // When this loop ends prev_ptr pointing towards my last node which is the new head
    Node* new_head=prev_ptr;
    return new_head;
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);

    print_linked_list(linked_list);

    linked_list=Reverse_linked_list(linked_list);

    print_linked_list(linked_list);
}