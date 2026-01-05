// Transform to Sum Tree

// Node Value= Node Value + left subtree sum + right subtree sum

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

int Sum_Tree(TreeNode* Root){
    if(Root==NULL){
        return 0;
    }

    Root->val += Sum_Tree(Root->left) + Sum_Tree(Root->right);

    return Root->val;
}

int main(){
    TreeNode* Root=new TreeNode(1);

    Root->left=new TreeNode(2);
    Root->right=new TreeNode(3);
    Root->right->left=new TreeNode(4);
    Root->right->right=new TreeNode(5);

    cout << Sum_Tree(Root);

    cout << Root->val;
}