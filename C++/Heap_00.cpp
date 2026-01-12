#include<iostream>

using namespace std;
int heap[10];
int size=0;
int m=0;

void heapify(int curr){
    int large=curr;
    int LC=2*curr +1;
    int RC=2*curr+2;

    if(LC<size && heap[large]<heap[LC]){
        large=LC;
    }
    if(RC<size && heap[large]<heap[RC]){
        large=RC;
    }

    if(large!=curr){
        int temp=heap[large];
        heap[large]=heap[curr];
        heap[curr]=temp;

        heapify(large);
    }
}


void add(int data){
    heap[size++]=data;
    m++;

    int curr=size-1;

    while(curr!=0){
        int p=(curr-1)/2;
        if(heap[p]<heap[curr]){
            int temp=heap[p];
            heap[p]=heap[curr];
            heap[curr]=temp;
            curr=p;
        }
        else{
            break;
        }
    }
}

int del(){
    int temp = heap[0];
    heap[0]=heap[size-1];
    size--;
    heapify(0);
    return temp;
}

void HeapSort(){
    int temp = heap[0];
    heap[0]=heap[size-1];
    heap[size-1]=temp;

    size--;
    heapify(0);
}

int main(){
    add(10);
    add(2);
    add(7);
    add(25);
    add(20);

    for(int i=0;i<=size-1;i++){
        cout << heap[i] << "  ";
    }
    cout << endl;

    HeapSort();
    HeapSort();
    HeapSort(); 
    HeapSort(); 
    HeapSort();
    
    for(int i=0;i<m;i++){
        cout << heap[i] << "  ";
    }
}