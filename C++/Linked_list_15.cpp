// Given 2 sorted linked lists, merge them into 1 singly linked list such that the resulting list is also sorted.

// In this code we are not creating any other linked list to store merged linked list
// we are just changing the connections of the nodes


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


Node* merge_linked_list(Node* head_1,Node* head_2){
    Node* dummy_node=new Node(-1);

    Node* temp=dummy_node;

    while(head_1!=NULL && head_2!=NULL){
        if((head_1->val)<(head_2->val)){
            temp->next=head_1;
            head_1=head_1->next;
        }
        else{
            temp->next=head_2;
            head_2=head_2->next;
        }
        temp=temp->next;
    }

    if (head_1 != NULL) {
        temp->next = head_1;
    } else {
        temp->next = head_2;
    }

    Node* merge_linked_list_head = dummy_node->next; // 1. Save the pointer to the real head
    delete dummy_node;                               // 2. Delete the dummy node
    return merge_linked_list_head;                   // 3. Return the saved pointer
}


int main(){
    Node* linked_list_1=new Node(1);

    insert_at_tail(linked_list_1,2);
    insert_at_tail(linked_list_1,3);
    insert_at_tail(linked_list_1,4);
    insert_at_tail(linked_list_1,5);

    print_linked_list(linked_list_1);


    Node* linked_list_2=new Node(1);

    insert_at_tail(linked_list_2,4);
    insert_at_tail(linked_list_2,9);
    insert_at_tail(linked_list_2,10);

    print_linked_list(linked_list_2);

    Node* merge_linked_list_head=merge_linked_list(linked_list_1,linked_list_2);

    print_linked_list(merge_linked_list_head);
}