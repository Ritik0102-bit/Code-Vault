// LCA (Lowest Common Ancestor)

// Time Complexity :- O(n)
// Space Complexity :- O(n)  for recursion stack

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

TreeNode* LCA(TreeNode* Root,TreeNode* node1,TreeNode* node2){
    if(Root==NULL){
        return NULL;
    }

    if(Root==node1 || Root==node2){
        return Root;
    }

    TreeNode* Left_LCA=LCA(Root->left,node1,node2);
    TreeNode* Right_LCA=LCA(Root->right,node1,node2);

    if(Left_LCA && Right_LCA){
        return Root;
    }
    else if(Left_LCA){
        return Left_LCA;
    }
    else{
        return Right_LCA;
    }
}

int main() {
    // Constructing a simple tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode* n4 = root->left->left;  // Node with val 4
    TreeNode* n5 = root->left->right; // Node with val 5
    TreeNode* n3 = root->right;       // Node with val 3

    // Case 1: LCA of 4 and 5 should be 2
    TreeNode* ans = LCA(root, n4, n5);
    if (ans) cout << "LCA of 4 and 5 is: " << ans->val << endl;

    // Case 2: LCA of 4 and 3 should be 1
    ans = LCA(root, n4, n3);
    if (ans) cout << "LCA of 4 and 3 is: " << ans->val << endl;

    return 0;
}