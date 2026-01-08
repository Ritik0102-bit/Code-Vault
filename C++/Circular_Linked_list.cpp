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

class Circular_Linked_List{
    public:
    Node* head;

    Circular_Linked_List(){
        head=NULL;
    }
};

void insert_At_start(Node* &head,int val){
    Node* new_node=new Node(val);

    if(head==NULL){
        head=new_node;
        new_node->next=head;
        return;
    }

    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    // Now temp is Pointing to last Node

    temp->next=new_node;
    new_node->next=head;
    head=new_node;
    return;
}

void insert_At_last(Node* &head,int val){
    Node* new_node=new Node(val);

    if(head==NULL){
        head=new_node;
        new_node->next=head;
        return;
    }

    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    // Now temp is Pointing to last Node

    temp->next=new_node;
    new_node->next=head;
    return;
}

void delete_from_start(Node* &head){
    if(head==NULL){
        return;
    }

    Node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }

    Node* temp=head;
    head=head->next;
    tail->next=head;
    delete temp;
    return;
}

void delete_from_last(Node* &head){
    if(head==NULL){
        return;
    }

    Node* tail=head;
    while(tail->next->next!=head){
        tail=tail->next;
    }

    Node* temp=tail->next;
    tail->next=tail->next->next;
    delete temp;
    return;
}

void print_Circular_LL(Node* head){
    if(head == NULL){
        cout << "List is empty." << endl;
        return;
    }
    
    Node* temp=head;

    do{
        cout << temp->val << " -> ";
        temp=temp->next;
    }while(temp!=head);
    cout << "HEAD" << endl;
}

int main(){
    Circular_Linked_List Circular_LL;

    insert_At_start(Circular_LL.head,5);
    insert_At_start(Circular_LL.head,4);
    insert_At_start(Circular_LL.head,3);
    insert_At_start(Circular_LL.head,2);
    insert_At_start(Circular_LL.head,1);

    insert_At_last(Circular_LL.head,7);

    print_Circular_LL(Circular_LL.head);
    
    delete_from_start(Circular_LL.head);
    delete_from_last(Circular_LL.head);
    delete_from_last(Circular_LL.head);
    
    print_Circular_LL(Circular_LL.head);

    return 0;
}