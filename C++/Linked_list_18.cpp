// Given the head of the linked list , determine if the linked list is a palindrome or not

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

bool is_palindrome(Node* &head){
    Node* slow=head;
    Node* fast=head;

    // First we need to find middle element
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    // Now slow is pointing to middle element
    // We will break the Linked list in the middle
    // we need to reverse the second half of linked list to check whether the both Halfs are same or not
    Node* curr=slow->next;
    Node* prev=slow;
    slow->next=NULL;

    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    Node* head1=head;
    Node* head2=prev;

    print_linked_list(head1);
    print_linked_list(head2);

    while(head2!=NULL){
        if(head1->val!=head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,1);

    print_linked_list(linked_list);

    cout << is_palindrome(linked_list);
}