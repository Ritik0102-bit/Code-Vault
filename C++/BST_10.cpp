// Merge Two BSTs

// Time Complexity :- O(m+n)

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node using 'class'
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function: Store in-order traversal of the tree in a vector
void storeInorder(TreeNode* root, vector<int>& inorder) {
    if (root == nullptr) return;
    
    storeInorder(root->left, inorder);
    inorder.push_back(root->val);
    storeInorder(root->right, inorder);
}

// Helper function: Merge two sorted vectors into one
vector<int> mergeArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }
    
    // Push remaining elements
    while (i < n) res.push_back(a[i++]);
    while (j < m) res.push_back(b[j++]);
    
    return res;
}

// Helper function: Convert sorted vector to Balanced BST
TreeNode* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;
    
    // Make the middle element the root to ensure balance
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    
    return root;
}

// Main Logic: Function to merge two BSTs
TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {
    // 1. Get sorted arrays for both trees
    vector<int> tree1, tree2;
    storeInorder(root1, tree1);
    storeInorder(root2, tree2);
    
    // 2. Merge the two arrays
    vector<int> mergedList = mergeArrays(tree1, tree2);
    
    // 3. Construct Balanced BST from merged array
    return sortedArrayToBST(mergedList, 0, mergedList.size() - 1);
}

// Utility: Print the tree (In-order) to verify result
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    // Create BST 1:    3
    //                 / \
    //                1   5
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    // Create BST 2:    4
    //                 / \
    //                2   6
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    // Merge the trees
    TreeNode* mergedRoot = mergeBST(root1, root2);

    cout << "In-order traversal of the merged balanced BST: ";
    printInorder(mergedRoot); 
    // Expected Output: 1 2 3 4 5 6
    
    return 0;
}