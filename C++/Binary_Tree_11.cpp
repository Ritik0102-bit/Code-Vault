// We need to check whether a target sum is present in any branch of tree or not

/*
            6
          /   \
         9     7
        /\     /\
       3  6   5  1   

*/

// 396 = 18 , 696 = 21 , 576 = 18 , 176 = 14
// target = 21
// ouput = 1

// target = 20
// ouput = 0

#include<iostream>

using namespace std;

class Tree_Node{
    public:
    int val;
    Tree_Node* left;
    Tree_Node* right;

    Tree_Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

int find_target_sum(Tree_Node* Root,int Target){
    if(Root==NULL){
        return 0;
    }

    if(Root->left==NULL && Root->right==NULL){
        if(Target-Root->val == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    Target = Target - Root->val;

    return find_target_sum(Root->left,Target)  ||  find_target_sum(Root->right,Target);
}

int main(){
    return 0;
}