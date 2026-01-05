// Kth Level of Binary Tree

#include<iostream>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

void Kth_level(TreeNode* Root,int K){
    if(Root==NULL){
        return;
    }
    
    if(K==1){
        cout << Root->val << " " ;
        return;
    }

    Kth_level(Root->left,K-1);
    Kth_level(Root->right,K-1);
}

int main(){
    TreeNode* Root=new TreeNode(1);

    Root->left=new TreeNode(2);
    Root->right=new TreeNode(2);
    Root->left->left=new TreeNode(3);
    Root->left->right=new TreeNode(3);
    Root->right->left=new TreeNode(3);
    Root->right->right=new TreeNode(3);

    Kth_level(Root,3);

    return 0;
}