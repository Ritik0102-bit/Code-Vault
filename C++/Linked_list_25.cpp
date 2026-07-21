// A critical point in a linked list is defined as either a local maxima or a local minima.

// Given a linked list tail, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points.

// If there are fewer than two critical points, return [-1, -1].

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>

using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};

void insert_at_tail(Node* &head,int value){
    Node* new_node=new Node(value);

    if(head==NULL){
        head=new_node;
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

void print_linked_list(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->val << " -> ";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

    vector<int> nodesBetweenCriticalPoints(Node* head) {
        // Edge case: If the list has fewer than 3 nodes, it can't have a critical point.
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int min_dist = INT_MAX;
        int first_crit_idx = -1;
        int prev_crit_idx = -1;
        
        Node* prev = head;
        Node* curr = head->next;
        
        int idx = 1; // We start at index 1 because head is index 0

        while (curr->next != nullptr) {
            Node* next_node = curr->next;

            // Check if current node is a critical point (local maxima or minima)
            if ((curr->val > prev->val && curr->val > next_node->val) || 
                (curr->val < prev->val && curr->val < next_node->val)) {
                
                // If it's the very first critical point we've found
                if (first_crit_idx == -1) {
                    first_crit_idx = idx;
                } else {
                    // If we already found a previous critical point, calculate min_dist
                    min_dist = min(min_dist, idx - prev_crit_idx);
                }
                
                // Update the previous critical point index to the current one
                prev_crit_idx = idx;
            }

            // Move pointers forward
            prev = curr;
            curr = next_node;
            idx++;
        }

        // If we found fewer than 2 critical points, min_dist will still be INT_MAX
        if (min_dist == INT_MAX) {
            return {-1, -1};
        }

        // max_dist is always the difference between the very last and very first critical points
        int max_dist = prev_crit_idx - first_crit_idx;

        return {min_dist, max_dist};
    }

int main() {
    // Initialize head to nullptr to avoid undefined behavior
    Node* head = nullptr; 

    // Let's create the list: [5, 3, 1, 2, 5, 1, 2]
    // Critical points will be at indices: 
    // - 2 (val 1, local minima)
    // - 4 (val 5, local maxima)
    // - 5 (val 1, local minima)
    insert_at_tail(head, 5);
    insert_at_tail(head, 3);
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 5);
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);

    cout << "Linked List: ";
    print_linked_list(head);

    // Call the function
    vector<int> result = nodesBetweenCriticalPoints(head);

    // Print the results
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}