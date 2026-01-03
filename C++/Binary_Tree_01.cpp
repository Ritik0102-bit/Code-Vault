// Level Order Traversal

// Level Order Traversal (also known as Breadth-First Search or BFS for trees) is a tree traversal algorithm where nodes are visited level by level, from left to right.

// Unlike Depth-First Traversals (Pre-order, In-order, Post-order) which go deep into a branch before backtracking, Level Order Traversal visits all nodes at depth d before moving to depth d+1.

// The Algorithm (Using a Queue):-
// Because we need to process nodes in a "First In, First Out" (FIFO) manner, a Queue is the perfect data structure.

// Create an empty queue.
// Push the root node into the queue.
// While the queue is not empty:
// Pop the front node.
// Print/Process that node's data.
// Push its left child (if it exists).
// Push its right child (if it exists).

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void Level_Order_Traversal(Node* root) {
    if (root == nullptr) return;

    // Create a queue for BFS
    queue<Node*> q;
    
    // Push the root first
    q.push(root);

    while (!q.empty()) {
        // Get the front node
        Node* current = q.front();
        q.pop();

        // Process current node
        cout << current->data << " ";

        // Enqueue left child
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Enqueue right child
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void Level_Order_Line_By_Line_Traversal(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at current level

        // Process ONLY the nodes of this level
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl; // New line after each level
    }
}

int main() {
    /* Constructed Tree:
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Level Order Traversal: ";
    Level_Order_Traversal(root);
    // Output: 1 2 3 4 5 6

    Level_Order_Line_By_Line_Traversal(root);

    return 0;
}