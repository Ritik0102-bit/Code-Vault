// Validate BST

// For BST :- left subtree (Maximum ele) < Root value < Right subtree (Minimum ele)

#include <iostream>
#include <climits>

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

// --- 1st Approach: Range-Based (Recursive) ---
bool isValidBST(TreeNode* root, long minVal, long maxVal) {
    if (root == nullptr) return true;

    if (root->val <= minVal || root->val >= maxVal) return false;

    // Left child must be < root->val; Right child must be > root->val
    return isValidBST(root->left, minVal, root->val) && 
           isValidBST(root->right, root->val, maxVal);
}

// --- 2nd Approach: Inorder Traversal ---
// We pass prevValue by reference so it persists across recursive calls
bool checkInorder(TreeNode* root, long &prevValue) {
    if (root == nullptr) return true;

    // 1. Visit Left Subtree
    if (!checkInorder(root->left, prevValue)) return false;

    // 2. Visit Current Node
    if (root->val <= prevValue) return false;
    prevValue = root->val;

    // 3. Visit Right Subtree
    return checkInorder(root->right, prevValue);
}

// Helper: Insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
        
    return root;
}

// Helper: Inorder display
void inorderDisplay(TreeNode* root) {
    if (root == nullptr) return;
    inorderDisplay(root->left);
    cout << root->val << " ";
    inorderDisplay(root->right);
}

int main() {
    TreeNode* Root = nullptr;
    
    // Creating a valid BST
    int values[] = {5, 3, 7, 2, 4, 8};
    for(int x : values) {
        Root = insert(Root, x);
    }

    cout << "BST Inorder Traversal: ";
    inorderDisplay(Root); // Expected: 2 3 4 5 7 8 
    cout << endl;
    
    // Testing Approach 1
    cout << "Validation (Approach 1): " << (isValidBST(Root, LONG_MIN, LONG_MAX) ? "True" : "False") << endl;

    // Testing Approach 2
    long prevValue = LONG_MIN; 
    cout << "Validation (Approach 2): " << (checkInorder(Root, prevValue) ? "True" : "False") << endl;

    return 0;
}