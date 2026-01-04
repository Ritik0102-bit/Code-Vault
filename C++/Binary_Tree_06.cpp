// Check whether a tree is subtree of another tree or not

// LeetCode 572 : Subtree of another Tree

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

static int idx=-1;
Node* Build_Tree(vector<int> Preorder){
    idx++;

    if(Preorder[idx]==-1){
        return NULL;
    }

    Node* Root=new Node(Preorder[idx]);

    Root->left=Build_Tree(Preorder);
    Root->right=Build_Tree(Preorder);

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

bool is_subtree(Node* Root,Node* Subtree_Root){
    if(Root==NULL || Subtree_Root==NULL){
        return Root==Subtree_Root;
    }

    if(Root->val == Subtree_Root->val && is_Identical(Root,Subtree_Root)){
        return true;
    }

    return is_subtree(Root->left,Subtree_Root) || is_subtree(Root->right,Subtree_Root);
}

int main(){
    vector<int> Preorder_sequence = {1 ,2 ,-1 , -1, 3 ,4 ,-1 , -1, 5 , -1, -1};

    Node* Root=Build_Tree(Preorder_sequence);

    Node* Subtree_Root=new Node(3);
    Subtree_Root->left=new Node(4);
    Subtree_Root->right=new Node(5);

    cout << is_subtree(Root,Subtree_Root);

    return 0;
}