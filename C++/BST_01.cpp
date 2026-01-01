// Searching In BST

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

bool search(TreeNode* Root,int key){
    if(Root==NULL){
        return false;
    }
    if(Root->val==key){
        return true;
    }
    if(Root->val>key){
        return search(Root->left,key);
    }
    else{
        return search(Root->right,key);
    }
}

int main(){
    int n;
    vector<int> v={3,2,1,5,6,4};

    TreeNode* Root = Build_BST(v);

    cout << search(Root,5);

}