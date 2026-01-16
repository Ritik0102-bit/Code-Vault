// Given the head of linked list , rotate the list to the right by k places

// 1 -> 2 -> 3 -> 4 -> 5 -> 6
// when k=1  6 -> 1 -> 2 -> 3 -> 4 -> 5
// when k=2  5 -> 6 -> 1 -> 2 -> 3 -> 4

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

void rotate_by_k_nodes(Node* &head,int k){
    Node* slow=head;
    Node* fast=head;

    while(k){
        fast=fast->next;
        k--;
    }

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next;
    }

    Node* temp=slow->next;
    slow->next=NULL;
    fast->next=head;
    head=temp;
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);

    print_linked_list(linked_list);

    rotate_by_k_nodes(linked_list,2);

    print_linked_list(linked_list);
}