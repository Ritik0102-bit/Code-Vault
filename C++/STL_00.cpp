// Template Classes
// they allow us to pass data type as parameter.

#include<iostream>

using namespace std;

template < typename T > 
// This T datatype will be defined on Runtime

class Node {
    public:
    T val;
    Node* next;

    Node(T data){
        val=data;
        next=NULL;
    }
};

int main(){
    Node<int>* node1=new Node<int>(3);
    cout << node1->val << endl;
    
    Node<char>* node2=new Node<char>('a');
    cout << node2->val << endl;
    
    Node<string>* node3=new Node<string>("Hello");
    cout << node3->val << endl;
    return 0;
}