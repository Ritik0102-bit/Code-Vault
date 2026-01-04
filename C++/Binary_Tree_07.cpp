// Calculate The Diameter of the Tree

// Diameter of a tree : The maximum distance between any two leafs of the tree

#include<iostream>
#include<vector>

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
Node* Build_Tree(vector<int> &Preorder){
    idx++;

    if(Preorder[idx]==-1){
        return NULL;
    }

    Node* Root=new Node(Preorder[idx]);

    Root->left=Build_Tree(Preorder);
    Root->right=Build_Tree(Preorder);

    return Root;
}

int ans=0;

int height(Node* Root){
    if(Root==NULL){
        return 0;
    }

    int left_height=height(Root->left);
    int right_height=height(Root->right);

    ans = max(left_height+right_height,ans);

    return max(left_height,right_height) + 1;
}

int diameter_of_Tree(Node* Root){
    height(Root);

    return ans;
}

int main(){
    vector<int> Preorder_sequence = {1 ,2 ,-1 , -1, 3 ,4 ,-1 , -1, 5 , -1, -1};

    Node* Root=Build_Tree(Preorder_sequence);

    cout << diameter_of_Tree(Root);

    return 0;
}