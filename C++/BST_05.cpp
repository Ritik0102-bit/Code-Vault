// Minimum Distance between BST Nodes

// It means we need to minimum difference between the values of any two nodes

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

TreeNode* previous=NULL;

int min_Diff_in_BST_nodes(TreeNode* Root){
    if(Root==NULL){
        return INT8_MAX;
    }

    int ans=INT8_MAX;

    if(Root->left!=NULL){
        int left_min=min_Diff_in_BST_nodes(Root->left);
        ans=min(ans,left_min);
    }

    if(previous!=NULL){
        ans=min(ans,Root->val - previous->val);
    }

    previous=Root;

    if(Root->right!=NULL){
        int Right_min=min_Diff_in_BST_nodes(Root->right);
        ans=min(ans,Right_min);
    }

    return ans;
}



#include <iostream>
#include <climits> // Required for INT_MAX
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// Global variables to track state across recursive calls
TreeNode* prevNode = NULL;
int minDiff = INT_MAX;

void inorder(TreeNode* root) {
    if (root == NULL) return;

    // 1. Traverse Left
    inorder(root->left);

    // 2. Process Current Node
    if (prevNode != NULL) {
        // Difference between current and previous in sorted order
        minDiff = min(minDiff, root->val - prevNode->val);
    }
    prevNode = root; // Update previous to current

    // 3. Traverse Right
    inorder(root->right);
}

int getMinimumDifference(TreeNode* root) {
    // Reset globals in case of multiple test cases
    prevNode = NULL;
    minDiff = INT_MAX;
    
    inorder(root);
    return minDiff;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "Minimum Difference: " << getMinimumDifference(root) << endl;

    return 0;
}