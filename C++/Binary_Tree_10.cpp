// Calculate The max number formed from every branch of tree

/*
            6
          /   \
         9     7
        /\     /\
       3  6   5  1   

*/

// 396,696 , 576 , 176
// max=696

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

int Maximum(Node* Root){
    if(Root==NULL){
        return 0;
    }

    int left=Maximum(Root->left);
    int right=Maximum(Root->right);

    return max(left*10 + Root->val , right*10 + Root->val);
}


int main(){
    Node* Root=new Node(6);
    Root->left=new Node(9);
    Root->right=new Node(7);
    Root->left->left=new Node(3);
    Root->left->right=new Node(6);
    Root->right->left=new Node(5);
    Root->right->right=new Node(1);

    cout << Maximum(Root) << endl;

    return 0;
}