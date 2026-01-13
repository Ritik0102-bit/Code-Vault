// Insert a listnode at the starting of a singly linked list

#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int data){
            val = data;
            next = NULL;
        }

};

// This function is used to insert an element at the starting of singly linked list
void insertAtHead(Node* &head, int val){
  Node* new_node = new Node(val);
  new_node->next = head;
  head = new_node;
}


// This function is used to print the linked list
void display(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->val<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}


int main(){

    Node* n = new Node(1);
    cout<<n->val<<" "<<n->next<<endl;

    display(n);
    
    insertAtHead(n,2);
    display(n);
    
    insertAtHead(n,3);
    display(n);

    insertAtHead(n,4);
    display(n);
    
    insertAtHead(n,5);
    display(n);

    return 0;
}