// 2 Pointers

// Given 2 linked lists, Tell if they are equal or not. Two linked lists are equal if they have the same data and the arrangement of data is also the same.

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

bool check_equal_Linked_list(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val!=temp2->val){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }

    if(temp1==NULL && temp2==NULL){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* linked_list_1=new Node(1);

    insert_at_tail(linked_list_1,2);
    insert_at_tail(linked_list_1,3);
    insert_at_tail(linked_list_1,4);
    insert_at_tail(linked_list_1,5);
    insert_at_tail(linked_list_1,6);

    print_linked_list(linked_list_1);


    Node* linked_list_2=new Node(1);

    insert_at_tail(linked_list_2,2);
    insert_at_tail(linked_list_2,3);
    insert_at_tail(linked_list_2,4);
    insert_at_tail(linked_list_2,5);
    insert_at_tail(linked_list_2,6);
    

    print_linked_list(linked_list_2);

    cout << check_equal_Linked_list(linked_list_1,linked_list_2);
}