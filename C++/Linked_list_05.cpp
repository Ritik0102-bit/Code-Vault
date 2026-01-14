// In this code we will see how to delete a node from different positions of a singly linked list

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

void insert_at_head(Node* &head,int val){
    Node* new_node=new Node(val);

    new_node->next=head;
    head=new_node;
}

void delete_at_head(Node* &head){
    Node* temp=head;
    head=head->next;
    free(temp);
}

void delete_at_tail(Node* &head){
    Node* temp=head;

    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    Node* tail_node=temp->next;
    temp->next=NULL;
    free(tail_node);
    
}

void delete_at_position(Node* &head,int position){
    Node* temp=head;

    int pos=1;
    while(pos!=position-1){
        temp=temp->next;
        pos++;
    }

    Node* target_node=temp->next;
    temp->next=temp->next->next;
    free(target_node);
}

void print_linked_list(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout << temp->val << " -> ";
        temp=temp->next;
    }
    cout << "Null" << endl;
}

int main(){
    Node* linked_list=new Node(5);

    insert_at_head(linked_list,4);
    insert_at_head(linked_list,3);
    insert_at_head(linked_list,2);
    insert_at_head(linked_list,1);
    insert_at_head(linked_list,0);

    print_linked_list(linked_list);
    
    delete_at_head(linked_list);
    
    print_linked_list(linked_list);

    delete_at_tail(linked_list);
    
    print_linked_list(linked_list);

    delete_at_position(linked_list,2);
    
    print_linked_list(linked_list);

    return 0;
}