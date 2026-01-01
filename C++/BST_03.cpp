// Sorted Array To Balanced BST

// Array = {-10 , -3 , 0 , 5 , 9}

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

TreeNode* Sorted_Array_To_BST(vector<int> &v,int startIdx,int endIdx){

    if(startIdx > endIdx){
        return NULL;
    }

    int mid = startIdx + (endIdx - startIdx)/2;

    TreeNode* Root = new TreeNode(v[mid]);

    Root->left = Sorted_Array_To_BST(v,startIdx,mid-1);
    Root->right = Sorted_Array_To_BST(v,mid+1,endIdx);

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
    vector<int> v = {-10 , -3 , 0 , 5 , 9};

    TreeNode* Root=Sorted_Array_To_BST(v,0,v.size()-1);

    Inorder_Traversal(Root);
    cout << endl;
}