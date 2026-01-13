// This code is to insert element at the last of the linked list

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


void insert_at_last(Node* &head,int val){
    Node* last_node=new Node(val);

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=last_node;
}

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->val << " -> ";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* n=new Node(1);

    insert_at_last(n,2);
    insert_at_last(n,3);
    insert_at_last(n,4);
    insert_at_last(n,5);

    display(n);
}