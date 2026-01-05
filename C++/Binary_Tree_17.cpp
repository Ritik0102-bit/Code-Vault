// Binary Tree Paths

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

// 1st Approach

void Binary_tree_paths(TreeNode* Root,string Path,vector<string> &ans){
    // 1. Base Case: If we reach a leaf, add the path to results
    if (Root->left == NULL && Root->right == NULL) {
        ans.push_back(Path);
        return;
    }

    // 2. Only recurse LEFT if the child exists
    if (Root->left != NULL) {
        Binary_tree_paths(Root->left, Path + " -> " + to_string(Root->left->val), ans);
    }

    // 3. Only recurse RIGHT if the child exists
    if (Root->right != NULL) {
        Binary_tree_paths(Root->right, Path + " -> " + to_string(Root->right->val), ans);
    }
}


// 2nd Approach
// This is more efficient

void Binary_tree_paths_2(TreeNode* root, vector<int>& currentPath, vector<string>& ans) {
    if (!root) return;

    // 1. Action: Add current node value to path
    currentPath.push_back(root->val);

    // 2. Base Case: If leaf node, convert path vector to formatted string
    if (!root->left && !root->right) {
        string pathStr = "";
        for (int i = 0; i < currentPath.size(); i++) {
            pathStr += to_string(currentPath[i]);
            if (i < currentPath.size() - 1) pathStr += " -> ";
        }
        ans.push_back(pathStr);
    } else {
        // 3. Recursion: Explore children
        if (root->left) Binary_tree_paths_2(root->left, currentPath, ans);
        if (root->right) Binary_tree_paths_2(root->right, currentPath, ans);
    }

    // 4. Backtrack: Remove current node before returning to parent
    currentPath.pop_back();
}

int main(){
    TreeNode* Root=new TreeNode(1);

    Root->left=new TreeNode(2);
    Root->right=new TreeNode(3);
    Root->right->left=new TreeNode(4);
    Root->right->right=new TreeNode(5);

    vector<string> ans;

    string path=to_string(Root->val);

    Binary_tree_paths(Root,path,ans);

    for(string i:ans){
        cout << i << endl;
    }



    vector<string> ans2;
    vector<int> currentPath;

    Binary_tree_paths_2(Root, currentPath, ans2);

    // Print the results
    for (string path : ans2) {
        cout << path << endl;
    }
}