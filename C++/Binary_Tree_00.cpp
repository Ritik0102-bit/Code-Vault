// Build a Binary Tree with preorder sequence

// Preorder Sequence : {1 ,2 ,-1 , -1, 3 ,4 ,-1 , -1, 5 , -1, -1}

// In Preorder Traversal : Root , Left , Right
// In Inorder Traversal : Left , Root , Right
// In Postorder Traversal : Left , Right , Root 

#include<iostream>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

static int idx=-1;

Node* Build_Tree(int preorder[]){

    idx++;

    if(preorder[idx]==-1){
        return NULL;
    }

    Node* root=new Node(preorder[idx]);
    root->left=Build_Tree(preorder);
    root->right=Build_Tree(preorder);

    return root;
}

void Preorder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }

    cout << Root->val << " ";
    Preorder_Traversal(Root->left);
    Preorder_Traversal(Root->right);
}


void Inorder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }

    Inorder_Traversal(Root->left);
    cout << Root->val << " ";
    Inorder_Traversal(Root->right);
}


void Postorder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }

    Postorder_Traversal(Root->left);
    Postorder_Traversal(Root->right);
    cout << Root->val << " ";
}


int main(){
    int Preorder[]={1 ,2 ,-1 , -1, 3 ,4 ,-1 , -1, 5 , -1, -1};

    Node* Root=Build_Tree(Preorder);

    cout << Root->val << endl;
    cout << Root->left->val << endl;
    cout << Root->right->val << endl;

    Preorder_Traversal(Root);
    cout << endl;
    Inorder_Traversal(Root);
    cout << endl;
    Postorder_Traversal(Root);
    cout << endl;

    return 0;
}