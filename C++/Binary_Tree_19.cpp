// Morris Inorder Traversal

// This algorithm is used to get Indorder Traversal Iteratively
// Beacause Recursive solution sometimes causes stack overflow on very deep trees

/*
        1
       / \
      2   3  
         / \
        4   5
          
   Inorder Sequence: 2, 1, 4, 3, 5
*/

// Inorder Predecessor :- Right Most Node in the left subtree

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

vector<int> Morris_Inorder_Traversal(TreeNode* Root){
    vector<int> ans;
    TreeNode* curr=Root;

    while(curr!=NULL){
        if(curr->left==NULL){
            ans.push_back(curr->val);
            curr=curr->right;
        }

        else{
            // Find Inorder Predecessor (IP)
            TreeNode* IP=curr->left;
            while(IP->right!=NULL && IP->right!=curr){
                IP=IP->right;
            }

            if(IP->right==NULL){
                IP->right=curr; // Create Thread
                curr=curr->left;
            }
            else{
                IP->right=NULL; // Delete Thread
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
    }

    return ans;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << "Morris Inorder Traversal: ";
    vector<int> ans=Morris_Inorder_Traversal(root); 

    for(int ele:ans){
        cout << ele << "  ";
    }
    // Output should be: 2 1 4 3 5

    return 0;
}