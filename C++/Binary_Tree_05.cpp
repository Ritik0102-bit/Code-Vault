// Check whether the two tree are Identical Or Not

// LeetCode 100 : Same Tree

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

Node* Build_Tree(vector<int> Preorder,int &idx){
    idx++;

    if(Preorder[idx]==-1){
        return NULL;
    }

    Node* Root=new Node(Preorder[idx]);

    Root->left=Build_Tree(Preorder,idx);
    Root->right=Build_Tree(Preorder,idx);

    return Root;
}

bool is_Identical(Node* Root_1,Node* Root_2){
    if(Root_1==NULL || Root_2==NULL){
        return Root_1==Root_2;
    }

    bool is_left_identical=is_Identical(Root_1->left,Root_2->left);
    bool is_right_identical=is_Identical(Root_1->right,Root_2->right);

    return Root_1->val==Root_2->val  &&  is_left_identical && is_right_identical;
}

int main(){
    vector<int> Preorder_sequence = {1 ,2 ,-1 , -1, 3 ,4 ,-1 , -1, 5 , -1, -1};

    int idx=-1;
    Node* Root_1=Build_Tree(Preorder_sequence,idx);
    idx=-1;
    Node* Root_2=Build_Tree(Preorder_sequence,idx);

    cout << is_Identical(Root_1,Root_2);

    return 0;
}