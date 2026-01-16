// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

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

void reorder_even_odd_LL(Node* &head){
    Node* even_head=new Node(0);

    Node* temp=head;
    Node* temp2=even_head;
    Node* prev=temp;
    while(temp && temp->next){
        temp2->next=temp->next;
        temp->next=temp->next->next;
        prev=temp;
        temp=temp->next;
        temp2=temp2->next;
    }

    temp2->next=NULL;

    if(temp){
        temp->next=even_head->next;
    }
    else{
        prev->next=even_head->next;
    }
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);
    insert_at_tail(linked_list,7);
    insert_at_tail(linked_list,8);
    insert_at_tail(linked_list,9);

    print_linked_list(linked_list);

    reorder_even_odd_LL(linked_list);

    print_linked_list(linked_list);
}