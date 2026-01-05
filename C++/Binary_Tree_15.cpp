// Build Tree From Preorder & Inorder Sequence

// Preorder = [3,9,20,15,7]
// Inorder = [9,3,15,20,7]

// Output :-
/*
      3
     / \
    9  20
      /  \
     15   7
*/

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

int search(vector<int> &Inorder,int left_bound,int right_bound,int value){
    for(int i=left_bound;i<=right_bound;i++){
        if(Inorder[i]==value){
            return i;
        }
    }
}

TreeNode* Build_tree(vector<int> &Preorder,vector<int> &Inorder,int &Preorder_Idx,int left_bound,int right_bound){
    if(left_bound > right_bound){
        return NULL;
    }

    TreeNode* Root=new TreeNode(Preorder[Preorder_Idx]);

    int inorder_Idx=search(Inorder,left_bound,right_bound,Preorder[Preorder_Idx]);
    
    Preorder_Idx++;

    Root->left=Build_tree(Preorder,Inorder,Preorder_Idx,left_bound,inorder_Idx-1);
    Root->right=Build_tree(Preorder,Inorder,Preorder_Idx,inorder_Idx+1,right_bound);

    return Root;
}

void printInorder(TreeNode* node) {
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main(){
    vector<int> Preorder = {3,9,20,15,7};
    vector<int> Inorder = {9,3,15,20,7};

    int preorder_idx=0;
    TreeNode* Root=Build_tree(Preorder,Inorder,preorder_idx,0,Inorder.size()-1);

    printInorder(Root);

    return 0;
}