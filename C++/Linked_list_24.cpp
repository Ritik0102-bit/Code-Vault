// 2 -> 8 -> 3 -> 2 -> 2 -> 9 -> 2 -> NULL
// arr={3,2}

// we need to delete array elements from the linked list

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

void delete_array_elements(Node* &head,int x){
    Node* temp=head;
    while(temp->next!=NULL){
        while(temp->val==x){
            temp->val=temp->next->val;
            temp->next=temp->next->next;
        }
        temp=temp->next;
    }
    if(temp->val==x){
        temp=NULL;
    }
    return;
}

void delete_array_elements_2(Node* &head,int x){
    return;
}

int main(){
    Node* linked_list=new Node(2);

    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,8);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,9);
    insert_at_tail(linked_list,2);

    print_linked_list(linked_list);
    
    int arr[2]={3,2};
    
    for(int i=0;i<2;i++){
        if(linked_list==NULL){
            break;
        }
        delete_array_elements(linked_list,arr[i]);
    }
    
    print_linked_list(linked_list);

    return 0;
}
