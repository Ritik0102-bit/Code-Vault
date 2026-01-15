// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.


// we know how to merge two linked lists so we will take two linked lists from the starting of the array 
// and pushback the merged linked list at the end 
// we will continously do this till we have only one linked list present in the array
// and at the last we have our final merged linked list


#include<iostream>
#include<vector>

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
    insert_at_tail(linked_list_1,5);

    Node* linked_list_2=new Node(3);
    insert_at_tail(linked_list_2,4);
    insert_at_tail(linked_list_2,5);

    Node* linked_list_3=new Node(6);
    insert_at_tail(linked_list_3,7);

    Node* linked_list_4=new Node(8);
    insert_at_tail(linked_list_4,9);
    insert_at_tail(linked_list_4,10);

    vector<Node*> v;
    
    v.push_back(linked_list_1);
    v.push_back(linked_list_2);
    v.push_back(linked_list_3);
    v.push_back(linked_list_4);

    for(int i=0;i<4;i++){
        print_linked_list(v[i]);
    }

    while(v.size()!=1){
        Node* merged_linked_list=merge_linked_list(v[0],v[1]);
        v.erase(v.begin());
        v.erase(v.begin());
        v.push_back(merged_linked_list);
    }

    print_linked_list(v[0]);

    return 0;
}