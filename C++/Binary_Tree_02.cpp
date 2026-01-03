// Height of the Tree

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
Node* Build_Tree(vector<int> Preorder){
    idx++;

    if(Preorder[idx]==-1){
        return NULL;
    }

    Node* Root=new Node(Preorder[idx]);

    Root->left=Build_Tree(Preorder);
    Root->right=Build_Tree(Preorder);

    return Root;
}

int Height_of_Tree(Node* Root){
    if(Root==NULL){
        return 0;
    }

    int left_height=Height_of_Tree(Root->left);
    int right_height=Height_of_Tree(Root->right);

    return max(left_height,right_height) + 1;
}

int main(){
    vector<int> Preorder_sequence = {1 ,2 ,-1 , -1, 3 ,4 ,-1 , -1, 5 , -1, -1};

    Node* Root=Build_Tree(Preorder_sequence);

    cout << "Height of Tree : " << Height_of_Tree(Root);

    return 0;
}