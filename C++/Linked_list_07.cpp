// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

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

void Print_linked_list(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout << temp->val << " -> ";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

void delete_duplicates(Node* &head){
    Node* temp=head;

    while(temp!=NULL && temp->next!=NULL){
        if(temp->val==temp->next->val){
            Node* deletion_node=temp->next;
            temp->next=temp->next->next;
            delete deletion_node;
        }
        else{
            temp=temp->next;
        }
    }
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);
    insert_at_tail(linked_list,6);
    insert_at_tail(linked_list,6);

    Print_linked_list(linked_list);

    delete_duplicates(linked_list);

    Print_linked_list(linked_list);
}