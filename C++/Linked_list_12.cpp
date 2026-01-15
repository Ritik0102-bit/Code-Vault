// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.


// First we will find length of both the linked lists
// and then we move both pointers in the linked lists to the same length 
// so that we can traverse the linked lists to find the intersection points


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

int get_length(Node* head){
    Node* temp=head;
    int length=0;

    while(temp!=NULL){
        length++;
        temp=temp->next;
    }

    return length;
}

Node* move_head_by_k(Node* head,int k){
    Node* temp=head;

    while(k--){
        temp=temp->next;
    }

    return temp;
}

Node* Find_intersection(Node* head_1,Node* head_2){
    int l1=get_length(head_1);
    int l2=get_length(head_2);

    Node* ptr1;
    Node* ptr2;
    if(l1<l2){
        ptr1=head_1;
        ptr2=move_head_by_k(head_2,l2-l1);
    }
    if(l1>l2){
        ptr1=move_head_by_k(head_1,l1-l2);
        ptr2=head_2;
    }

    while(ptr1){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return NULL;
}

int main(){
    Node* linked_list_1=new Node(1);

    insert_at_tail(linked_list_1,2);
    insert_at_tail(linked_list_1,3);
    insert_at_tail(linked_list_1,4);
    insert_at_tail(linked_list_1,5);
    insert_at_tail(linked_list_1,6);

    print_linked_list(linked_list_1);


    Node* linked_list_2=new Node(7);

    insert_at_tail(linked_list_2,8);
    insert_at_tail(linked_list_2,9);
    insert_at_tail(linked_list_2,10);
    
    // we are creating a intersection between the linked lists
    linked_list_2->next->next->next->next=linked_list_1->next->next->next;

    print_linked_list(linked_list_2);
    
    Node* intersection= Find_intersection(linked_list_1,linked_list_2);

    if(intersection){
        cout << intersection->val;
    }
    else {
        cout << "No Intersection Between the Linked lists";
    }
    return 0;
}