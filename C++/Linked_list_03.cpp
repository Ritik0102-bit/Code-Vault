// This code is to insert an element at an arbitary position in a singly linked list

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

void insert_at_position(Node* &head,int position,int val){
    Node* new_node=new Node(val);

    int pos=0;
    if(position==0){
        new_node->next=head;
        head=new_node;
        return;
    }

    Node* temp=head;
    while(pos!=position-1){
        temp=temp->next;
        pos++;
    }

    new_node->next=temp->next;
    temp->next=new_node;
}

void display(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout << temp->val << " -> ";
        temp=temp->next;
    }
    cout << "NULL";
}

int main(){
    Node* n=new Node(1);

    insert_at_position(n,1,2);
    insert_at_position(n,2,3);
    insert_at_position(n,3,4);
    insert_at_position(n,4,5);

    display(n);
}