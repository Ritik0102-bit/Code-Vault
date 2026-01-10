// Given the head of a doubly linked list, find if it's a palindrome or not.

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

    void print_Doubly_LL(){
        Node* temp=head;
        while(temp!=NULL){
            cout << temp->val << " -> ";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }

};

bool isPalindromeDLL(Node* head, Node* tail){

    while(head!=tail && tail!=head->prev){
        if(head->val != tail->val){
            return false;
        }

        head=head->next;
        tail=tail->prev;

    }
    return true;
}

int main(){
    Doubly_linked_list Doubly_LL;

    Doubly_LL.insert_at_last(1);
    Doubly_LL.insert_at_last(2);
    Doubly_LL.insert_at_last(3);
    Doubly_LL.insert_at_last(4);
    Doubly_LL.insert_at_last(4);
    Doubly_LL.insert_at_last(3);
    Doubly_LL.insert_at_last(2);
    Doubly_LL.insert_at_last(1);

    Doubly_LL.print_Doubly_LL();

    cout << isPalindromeDLL(Doubly_LL.head,Doubly_LL.tail);
}