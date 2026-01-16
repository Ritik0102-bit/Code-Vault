// Given a linked list, swap every two adjacent nodes and return its head. You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// 1 -> 2 -> 3 -> 4 -> 5 -> 6
// after Swap : 2 -> 1 -> 4 -> 3 -> 6 -> 5

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

Node* swapAdjacent(Node* &head){

    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    //recursive case
    Node* secondNode = head->next;
    head->next = swapAdjacent(secondNode->next);
    secondNode->next = head; //reversing the link between first and second node
    return secondNode;
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);
    insert_at_tail(linked_list,7);

    print_linked_list(linked_list);

    linked_list=swapAdjacent(linked_list);

    print_linked_list(linked_list);
}