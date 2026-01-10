// Given the head of a doubly linked list, delete the nodes whose neighbors have the same value. Traverse the list from right to left.

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

void deleteSameNeighbourNode(Node* &head, Node* &tail){
    Node* currNode = tail->prev; //second last node
    while(currNode!=head){
    Node* prevNode = currNode->prev;
        Node* nextNode = currNode->next;
        if(prevNode->val==nextNode->val){
           // I need to delete the curr node
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
        }
        currNode = prevNode;
    }
}

int main(){
    Doubly_linked_list Doubly_LL;

    Doubly_LL.insert_at_last(2);
    Doubly_LL.insert_at_last(1);
    Doubly_LL.insert_at_last(1);
    Doubly_LL.insert_at_last(2);
    Doubly_LL.insert_at_last(1);

    Doubly_LL.print_Doubly_LL();
    
    deleteSameNeighbourNode(Doubly_LL.head,Doubly_LL.tail);

    Doubly_LL.print_Doubly_LL();
}