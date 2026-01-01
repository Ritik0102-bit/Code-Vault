// Kth smallest element in a BST

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

TreeNode* Insert_Node(TreeNode* Root,int val){
    if(Root==NULL){
        return new TreeNode(val);
    }

    if(val < Root->val){
        Root->left = Insert_Node(Root->left,val);
    }
    else{
        Root->right = Insert_Node(Root->right,val);
    }

    return Root;
}

void Inorder_Traversal(TreeNode* Root){
    if(Root==NULL){
        return;
    }

    Inorder_Traversal(Root->left);
    cout << Root->val << " ";
    Inorder_Traversal(Root->right);
}


int i=0;
int Kth_Smallest_BST(TreeNode* Root,int k){
    if(Root==NULL){
        return -1;
    }

    if(Root->left!=NULL){
        int left= Kth_Smallest_BST(Root->left,k);
        if(left!=-1){
            return left;
        }
    }
    
    i++;
    if(k==i){
        return Root->val;
    }
    
    if(Root->right!=NULL){
        int right= Kth_Smallest_BST(Root->right,k);
        if(right!=-1){
            return right;
        }
    }

    return -1;
}

int main(){
    vector<int> v={2,4,1,3,6,9,5};

    TreeNode* Root=NULL;

    for(int ele:v){
        Root = Insert_Node(Root,ele);
    }

    int kth_smallest = Kth_Smallest_BST(Root,7);
    cout << kth_smallest << endl;

    Inorder_Traversal(Root);

    return 0;
}