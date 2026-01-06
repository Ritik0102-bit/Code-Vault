// Flatten Binary Tree To Linked List

//        1
//       / \
//      2   5
//     / \   \
//    3   4   6

// Follow Preorder :- Root -> left -> right

// Output :- 1  -> 2  -> 3  -> 4  -> 5  -> 6

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

class Solution {
private:
    // Moved inside the class so it resets for every new test case
    TreeNode* Next_Right = NULL;

public:
    void flatten_Binary_Tree(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        // 1. Traverse Right
        flatten_Binary_Tree(root->right);
        
        // 2. Traverse Left
        flatten_Binary_Tree(root->left);

        // 3. Process Root
        root->left = NULL;
        root->right = Next_Right;
        
        // Update the pointer for the next recursive step
        Next_Right = root;
    }
};
