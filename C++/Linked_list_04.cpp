// This code is to update value at a position in a singly linked list

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

void insert_at_head(Node* &head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}


void update_value(Node* &head,int pos,int value){
    Node* temp=head;

    int position=0;
    while(position!=pos-1){
        temp=temp->next;
        position++;
    }

    temp->val=value;
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
    Node* head=new Node(6);

    insert_at_head(head,5);
    insert_at_head(head,4);
    insert_at_head(head,3);
    insert_at_head(head,2);
    insert_at_head(head,1);

    display(head);

    update_value(head,2,8);

    display(head);
}
