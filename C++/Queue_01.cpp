// Implementation of Queue By Linked List

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

class Queue{
    Node* front;
    Node* rear;
    int size;
    public:
    Queue(){
        front=NULL;
        rear=NULL;
        size=0;
    }

    void enque(int value){
        Node* new_node=new Node(value);
        this->size++;

        if(this->front==NULL){
            this->front=new_node;
            this->rear=new_node;
            return;
        }

        this->rear->next=new_node;
        this->rear=new_node;
        return;
    }

    void dequeue(){
        // if Queue is Empty
        if(this->front==NULL){
            return;
        }
        Node* node_to_delete=this->front;
        this->front=this->front->next;
        delete node_to_delete;
        this->size--;

        // If Queue Has Only one Element
        if(this->front==NULL){
            this->rear=NULL;
            return;
        }
    }

    int Front(){
        return this->front->val;
    }

    bool is_empty(){
        return this->size==0;
    }

    int Size(){
        return this->size;
    }
};

int main(){
    Queue Q;
    
    cout << Q.is_empty() << endl;

    Q.enque(0);
    Q.enque(1);
    Q.enque(2);
    Q.enque(3);
    Q.enque(4);
    Q.enque(5);
    Q.enque(6);
    
    cout << Q.Size() << endl;
    
    Q.dequeue();

    cout << Q.Size() << endl;

    while(!Q.is_empty()){
        cout << Q.Front() << " " ;
        Q.dequeue();
    }

    return 0;
}