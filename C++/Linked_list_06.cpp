// Given the head of a linked list, delete every alternate element from the list starting from the second element.

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

class linked_list{
    public:
    Node* head;

    linked_list(){
        head=NULL;
    }

    void insert_at_tail(int value){
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

    
    void Print_linked_list(){
        Node* temp=head;
        
        while(temp!=NULL){
            cout << temp->val << " -> ";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
};

void alternate_deletion(Node* &head){
    Node* temp=head;

    while(temp!=NULL && temp->next!=NULL){
        Node* deletion_node=temp->next;
        temp->next=temp->next->next;
        free(deletion_node);
        temp=temp->next;
    }
}

int main(){
    linked_list li;

    li.insert_at_tail(1);
    li.insert_at_tail(2);
    li.insert_at_tail(3);
    li.insert_at_tail(4);
    li.insert_at_tail(5);
    li.insert_at_tail(6);

    li.Print_linked_list();
    
    alternate_deletion(li.head);

    li.Print_linked_list();
}