// Top View Of Binary Tree

/*
        1
       / \
      2   3
         / \
        4   5
*/

// Top View :- 2 , 1 , 3 , 5

#include<iostream>
#include<vector>
#include<queue>
#include<map>

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

// 1st Approach

// Time Complexity :- O(nlogn)    n for traversal & logn for find() function
// Space Complexity :- O(n)

void Top_view(Tree_Node* Root){
    // we are going to store pair value for each node in queue & map
    queue<pair<Tree_Node*,int>> q; // (Tree Node , HD)
    map<int,int> m; // (HD , value)

    q.push({Root,0});

    while(q.size()>0){
        Tree_Node* curr_node=q.front().first;
        int curr_HD=q.front().second;

        q.pop();

        if(m.find(curr_HD)==m.end()){
            m[curr_HD]=curr_node->val;
        }

        if(curr_node->left!=NULL){
            q.push({curr_node->left,curr_HD-1});
        }

        if(curr_node->right!=NULL){
            q.push({curr_node->right,curr_HD+1});
        }
    }

    for(auto ele:m){
        cout << ele.second << "  ";
    }
}

// 2nd Approach 

// In this approach we are using one queue to store all the left node values & second queue to store all the right node values
// and then print first queue in reverse order and second queue in original order

int main(){
    Tree_Node* Root=new Tree_Node(1);
    Root->left=new Tree_Node(2);
    Root->right=new Tree_Node(3);
    Root->right->left=new Tree_Node(4);
    Root->right->right=new Tree_Node(5);

    Top_view(Root);

    return 0;
}