// You are given with the head of the linked list , determine if the linked list has the cycle in it.

// In this Problem first we need to find the cycle in the linked list
// If it is present then we need to remove the cycle

// Ex - 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8  
// when the 8 is again connected to any element of the linked list , then it forms a cyclic loop 
// Because there is no NULL present in the linked list

// This Problem is solved with the SLOW & FAST POINTER 

#include<iostream>

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

bool Find_cycle(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            cout << slow->val << endl;
            return true;
        }
    }

    return false;
}

// To remove the cycle 
// we will traverse our linked list with the help of slow & fast pointer till they met at a common point
// Then from that point & the Head ,the distance of the node where the Cycle is formed in the linked list is same
// So we will store NULL in next of that node
void remove_cycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    // 1. Find the collision point (same as your Find_cycle)
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break; // Collision found
        }
    }

    // If no cycle, nothing to remove
    if (fast == NULL || fast->next == NULL) {
        return;
    }

    // 2. Find the start of the loop
    fast = head; // Reset fast pointer to the head

    // Case 1: The cycle starts at the head
    // If fast and slow meet at the head, the last node points to the head.
    if (slow == fast) {
        // We need to find the node *before* the head
        while (slow->next != fast) {
            slow = slow->next;
        }
        // slow is now at the last node of the cycle
    }
    // Case 2: The cycle starts somewhere else (your example)
    else {
        // Move both pointers one step at a time.
        // The node *before* they meet is the end of the loop.
        while (fast->next != slow->next) {
            fast = fast->next;
            slow = slow->next;
        }
        // slow is now at the last node of the cycle
    }

    // 3. Break the cycle
    slow->next = NULL;
}

int main(){
    Node* linked_list=new Node(1);

    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,4);
    insert_at_tail(linked_list,5);
    insert_at_tail(linked_list,6);
    insert_at_tail(linked_list,7);
    insert_at_tail(linked_list,8);

    // we are connecting the last node with the third node to create a cycle
    linked_list->next->next->next->next->next->next->next->next=linked_list->next->next;

    if(Find_cycle(linked_list)){
        remove_cycle(linked_list);
        cout << "Linked list after removing cycle : ";
        print_linked_list(linked_list);
    }
    else{
        cout << "No Cycle Found in linked list";
        print_linked_list(linked_list);
    }

    return 0;
}




// 2nd approach 

// 1. This function finds AND returns the collision node
// Node* getCollisionPoint(Node* head) {
//     Node* slow = head;
//     Node* fast = head;

//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//         if (slow == fast) {
//             return slow; // Return the meeting point
//         }
//     }
//     return NULL; // No cycle
// }

// // 2. This function assumes a collision has happened and just removes it
// void removeCycle(Node* head, Node* collisionPoint) {
//     Node* slow = collisionPoint;
//     Node* fast = head;

//     if (slow == fast) {
//         while (slow->next != fast) {
//             slow = slow->next;
//         }
//     } else {
//         while (fast->next != slow->next) {
//             fast = fast->next;
//             slow = slow->next;
//         }
//     }
//     slow->next = NULL;
// }

// // 3. Your main function becomes cleaner
// int main() {
//     Node* linked_list=new Node(1);

//     insert_at_tail(linked_list,2);
//     insert_at_tail(linked_list,3);
//     insert_at_tail(linked_list,4);
//     insert_at_tail(linked_list,5);
//     insert_at_tail(linked_list,6);
//     insert_at_tail(linked_list,7);
//     insert_at_tail(linked_list,8);
    
//     // Create the cycle
//     linked_list->next->next->next->next->next->next->next->next = linked_list->next->next;

//     Node* collision = getCollisionPoint(linked_list);

//     if (collision != NULL) {
//         cout << "Cycle found. Removing cycle..." << endl;
//         removeCycle(linked_list, collision);
//         cout << "Linked list after removing cycle: ";
//         print_linked_list(linked_list);
//     } else {
//         cout << "No Cycle Found in linked list: ";
//         print_linked_list(linked_list);
//     }

//     return 0;
// }