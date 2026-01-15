// Given the head of a linked list, remove the k-th node from the end of the list and return its head.

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


void remove_Kth_Node_From_End(Node* &head, int k){

    Node* ptr1 = head;
    Node* ptr2 = head;

    //move ptr2 by k steps ahead
    int count = k;
    while(count--){
        ptr2=ptr2->next;
    }

    if(ptr2==NULL){ //k is equal to length of linked list
        //we have to delete head node
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // now ptr2 is k steps ahead of ptr1
    //when ptr2 is at null (end of list), ptr1 will be at node to be deleted
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    //now ptr1 is pointing to the node before kth node from end
    // node to be deleted is ptr1->next
    Node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete temp;

}


int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);

    print_linked_list(linked_list);

    remove_Kth_Node_From_End(linked_list,5);

    print_linked_list(linked_list);
}