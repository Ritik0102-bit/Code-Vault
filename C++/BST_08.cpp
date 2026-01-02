// Lowest Common Ancestor

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

TreeNode* Lowest_Common_Ancestor(TreeNode* Root,TreeNode* p,TreeNode* q){
    if(Root==NULL){
        return NULL;
    }

    if(Root->val > p->val && Root->val > q->val){
        return Lowest_Common_Ancestor(Root->left,p,q);
    }
    if(Root->val < p->val && Root->val < q->val){
        return Lowest_Common_Ancestor(Root->right,p,q);
    }
    else{
        return Root;
    }
}


int main() {
    /* Constructing a sample BST:
                6
               / \
              2   8
             / \ / \
            0  4 7  9
              / \
             3   5
    */
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    // Define target nodes p and q
    TreeNode* p = root->left;        // Node with value 2
    TreeNode* q = root->left->right; // Node with value 4

    TreeNode* lca = Lowest_Common_Ancestor(root, p, q);

    if (lca != NULL) {
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}