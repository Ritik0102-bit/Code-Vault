/*
    You are given the head of a singly linked-list.
    The list can be represented as:
    L0 -> L1 -> ... -> Ln-1 -> Ln

    Reorder the list to be on the following form:
    L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...

    Means : 1st ele -> last ele -> 2nd ele -> 2nd last ele -> 3rd ele -> 3rd last ele ..........
*/

// So first we will reverse 2nd half of linked list 
// then we will pick one element from 1st Half & one element from 2nd Half

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

Node* reorder_LL(Node* &head){
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* mid=slow;

    Node* prev=mid;
    Node* curr=mid->next;
    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    mid->next=NULL;
    print_linked_list(head); // 1st Half of Linked list
    print_linked_list(prev); // 2nd Half of Linked list

    Node* new_node=new Node(1);

    Node* temp=new_node;
    while(head && prev){
        temp->next=head;
        head=head->next;
        temp=temp->next;

        temp->next=prev;
        prev=prev->next;
        temp=temp->next;
    }
    temp->next=NULL;

    return new_node->next;
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);
    insert_at_tail(linked_list,7);
    // insert_at_tail(linked_list,8);

    print_linked_list(linked_list);

    linked_list=reorder_LL(linked_list);

    print_linked_list(linked_list);
}