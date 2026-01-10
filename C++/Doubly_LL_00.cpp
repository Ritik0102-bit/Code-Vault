#include<iostream>

using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};

class Doubly_linked_list{
    public:
    Node* head;
    Node* tail;

    Doubly_linked_list(){
        head=NULL;
        tail=NULL;
    }

    void insert_at_head(int data){
        Node* new_node=new Node(data);

        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }

        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
    }

    void insert_at_last(int data){
        Node* new_node=new Node(data);

        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }

        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    }

    void insert_at_k_position(int k, int value) {
        
        // Handle: k is not a valid position
        if (k < 1) {
            cout << "Invalid position." << endl;
            return;
        }
        
        Node* temp = head;
        int c = 1;

        // Handle: List is empty
        if (temp == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        // Traverse to the k-th node
        while (c < k && temp != NULL) {
            temp = temp->next;
            c++;
        }

        // Handle: k is out of bounds (larger than list size)
        if (temp == NULL) {
            cout << "Position " << k << " is out of bounds." << endl;
            return;
        }

        // Handle: We are at the tail node.
        // If we insert after the tail, just use insert_at_last.
        if (temp->next == NULL) { // or (temp == tail)
            insert_at_last(value);
            return;
        }

        // --- Your original logic (which is correct for the middle) ---
        Node* new_node = new Node(value);
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
        return;
    }

    void delete_from_Start(){
        if(head==NULL){
            return;
        }

        Node* temp = head;
        head = head->next;
        if(head==NULL){ //if doubly linked list had only 1 node
            tail = NULL;
        }
        else{
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    void delete_from_End(){
        if(head==NULL){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if(tail==NULL){
            head=NULL;
        }else{
            tail->next=NULL;
        }

        delete temp;
        return;
    }

    void delete_from_k_Position(int k){

        // Handle: Empty list or invalid k
        if(head == NULL || k < 1){
            return;
        }

        // Handle: Deleting the head node
        if(k == 1){
            delete_from_Start();
            return;
        }

        Node* temp = head;
        int counter = 1;
        
        // Traverse to the k-th node
        while(counter < k && temp != NULL){
            temp=temp->next;
            counter++;
        }

        // Handle: k is out of bounds (larger than list size)
        if(temp == NULL){
            cout << "Position " << k << " is out of bounds." << endl;
            return;
        }

        // Handle: Deleting the tail node
        if(temp == tail) { // or (temp->next == NULL)
            delete_from_End();
            return;
        }

        // Handle: Deleting a middle node
        // We know temp is not head (k=1 check) and not tail (tail check)
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        delete temp; // Use delete, not free
    }

    void print_from_start(){
        Node* temp=head;
        while(temp!=NULL){
            cout << temp->val << " -> ";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }

    void print_from_last(){
        Node* temp=tail;
        while(temp!=NULL){
            cout << temp->val << " -> ";
            temp=temp->prev;
        }
        cout << "NULL" << endl;
    }
};


int main(){
    Doubly_linked_list Doubly_LL;

    Doubly_LL.insert_at_head(5);
    Doubly_LL.insert_at_head(4);
    Doubly_LL.insert_at_head(3);
    Doubly_LL.insert_at_head(2);
    Doubly_LL.insert_at_head(1);
    Doubly_LL.insert_at_head(0);

    Doubly_LL.insert_at_last(6);
    Doubly_LL.insert_at_last(7);
    Doubly_LL.insert_at_last(8);

    Doubly_LL.insert_at_k_position(3,100);

    Doubly_LL.print_from_start();
    Doubly_LL.print_from_last();

    Doubly_LL.delete_from_Start();
    Doubly_LL.delete_from_End();

    Doubly_LL.print_from_start();

    Doubly_LL.delete_from_k_Position(5);

    Doubly_LL.print_from_start();
}