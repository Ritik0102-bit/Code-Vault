// Binary Search Tree

// Left Sub tree < Root < Right Sub tree

//       3
//      / \
//     2   5
//    /   / \
//   1   4   6

// (Note: In a BST, an Inorder Traversal always results in sorted data.)

#include<iostream>
#include<vector>

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

TreeNode* InsertNode(TreeNode* Root,int val){
    if(Root==NULL){
        return new TreeNode(val);
    }
    if(val<Root->val){
        Root->left = InsertNode(Root->left,val);
    }
    else{
        Root->right = InsertNode(Root->right,val);
    }

    return Root;
}

TreeNode* Build_BST(vector<int> &v){
    TreeNode* Root=NULL;

    for(int i:v){
        Root=InsertNode(Root,i);
    }

    return Root;
}

void Inorder_Traversal(TreeNode* Root){
    if(Root==NULL){
        return ;
    }

    Inorder_Traversal(Root->left);
    cout << Root->val << "  ";
    Inorder_Traversal(Root->right);
}

int main(){
    int n;
    vector<int> v={3,2,1,5,6,4};

    TreeNode* Root = Build_BST(v);

    Inorder_Traversal(Root);

    return 0;
}