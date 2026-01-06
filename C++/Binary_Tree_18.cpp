// Maximum Width of Binary Tree

#include<iostream>
#include<queue>

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

int Width_of_Binary_Tree(TreeNode* Root){
    int width=0;
    queue<pair<TreeNode*,unsigned long long>> q;

    q.push({Root,0});

    while(q.size()>0){
        int curr_size = q.size();

        unsigned long long startIdx=q.front().second;
        unsigned long long endIdx=q.back().second;

        width = max(width , (int)(endIdx-startIdx+1));

        for(int i=0;i<curr_size;i++){
            auto curr = q.front();
            q.pop();

            if(curr.first->left){
                q.push({curr.first->left,curr.second*2 + 1});
            }
            if(curr.first->right){
                q.push({curr.first->right,curr.second*2 + 2});
            }
        }
    }

    return width;
}

int main() {
    /* Constructing the following tree:
                1
              /   \
             3     2
            / \     \
           5   3     9
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << "Maximum Width of Binary Tree: " << Width_of_Binary_Tree(root) << endl;

    return 0;
}