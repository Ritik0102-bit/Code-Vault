// Deleting A Node From BST

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

// Helper function to find the Inorder Successor (Smallest in Right Subtree)
TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* DeleteNode(TreeNode* Root, int key) {
    if (Root == NULL) return Root;

    // 1. SEARCH for the node
    if (key < Root->val) {
        Root->left = DeleteNode(Root->left, key);
    } 
    else if (key > Root->val) {
        Root->right = DeleteNode(Root->right, key);
    } 
    else {
        // We found the node to delete!

        // CASE 1: No child (Leaf Node)
        // CASE 2: One child
        if (Root->left == NULL) {
            TreeNode* temp = Root->right;
            delete Root;
            return temp;
        } 
        else if (Root->right == NULL) {
            TreeNode* temp = Root->left;
            delete Root;
            return temp;
        }

        // CASE 3: Two children
        // Find Inorder Successor (Smallest value in the right subtree)
        else{
        TreeNode* Inorder_Successor = findMin(Root->right);

        // Copy the successor's content to this node
        Root->val = Inorder_Successor->val;

        // Delete the successor (which is now a duplicate in the right subtree)
        Root->right = DeleteNode(Root->right, Inorder_Successor->val);
        }
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
    cout << endl;
    
    Root=DeleteNode(Root,3);
    
    Inorder_Traversal(Root);
    cout << endl;
}