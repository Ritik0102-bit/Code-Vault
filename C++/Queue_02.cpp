// Implementation of Queue By Array
// Dynamic Array -> Vector

#include<iostream>
#include<vector>

using namespace std;

class Queue{
    vector<int> v;
    int front,rear,size;

    public:
    Queue(){
        front=rear=0;
        size=0;
    }

    void enqueue(int value){
        v.push_back(value);
        this->rear++;
        this->size++;
    }
    
    void dequeue(){
        if(is_empty()){
            cout << "Queue Underflow" << endl;
            return;
        }
        // If it has only one element
        if(this->front==this->rear){
            this->front=0;
            this->rear=0;
        }
        else{
            this->front++;
        }
        this->size--;
    }

    int Front(){
        if(is_empty()){
            return -1;
        }
        return v[this->front];
    }

    int Size(){
        return this->size;
    }

    bool is_empty(){
        return this->size==0;
    }
};

int main(){
    Queue Q;

    Q.enqueue(0);
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);

    while(!Q.is_empty()){
        cout << Q.Front() << " ";
        Q.dequeue();
    }

    return 0;
}