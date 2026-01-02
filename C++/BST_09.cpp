// Construct BST from Preorder Sequence

// Time Complexity:- O(n)

#include<iostream>
#include<vector>
#include <climits> // Required for INT_MAX

using namespace std ;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
            val=data;
            left=nullptr ;
            right = nullptr ;

    }
};

TreeNode* Build_BST(vector<int> &preorder_sequ,int &idx,int upper_bound){
    if(idx>=preorder_sequ.size() || preorder_sequ[idx] > upper_bound){
        return NULL;
    }

    TreeNode* Root = new TreeNode(preorder_sequ[idx]);
    idx++;

    Root->left = Build_BST(preorder_sequ,idx,Root->val);
    Root->right = Build_BST(preorder_sequ,idx,upper_bound);

    return Root;
}

void inorder_traversal(TreeNode* Root){
    if(Root==NULL){
        return;
    }

    inorder_traversal(Root->left);
    cout << Root->val << " ";
    inorder_traversal(Root->right);
}

int main() {
    // Example Preorder Sequence: 8, 5, 1, 7, 10, 12
    //        8
    //      /   \
    //     5     10
    //    / \      \
    //   1   7      12
    
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    int idx = 0;

    // We pass INT_MAX as the initial upper bound because the root can be any valid integer
    TreeNode* root = Build_BST(preorder, idx, INT_MAX);

    cout << "Inorder Traversal (Should be sorted): ";
    inorder_traversal(root);
    cout << endl;

    return 0;
}