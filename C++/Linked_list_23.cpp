// Sorting On Linked List

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

// 1st Approach

void Sort_Linked_List(Node* &linked_list){
    
    for(Node* ptr1=linked_list;ptr1!=NULL;ptr1=ptr1->next){
        for(Node* ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next){
            if(ptr1->val > ptr2->val){
                int temp=ptr1->val;
                ptr1->val=ptr2->val;
                ptr2->val=temp;
            }
        }
    }
}


// 2nd Approach
// This is the Best Approach

// 1. Helper Function: Merge two sorted lists
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = NULL;

    if (left->val <= right->val) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// 2. Helper Function: Find the middle node (to split list)
Node* getMiddle(Node* head) {
    if (head == NULL) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 3. Main Merge Sort Function
Node* Merge_Sort(Node* head) {
    // Base case: 0 or 1 node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Step 1: Split List
    Node* middle = getMiddle(head);
    Node* right_half = middle->next;
    middle->next = NULL; // Break the link

    // Step 2: Sort both halves recursively
    Node* left = Merge_Sort(head);
    Node* right = Merge_Sort(right_half);

    // Step 3: Merge sorted halves
    return merge(left, right);
}

int main(){
    Node* linked_list=new Node(5);

    insert_at_tail(linked_list,0);
    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,1);
    insert_at_tail(linked_list,6);
    insert_at_tail(linked_list,3);
    insert_at_tail(linked_list,2);
    insert_at_tail(linked_list,-1);

    print_linked_list(linked_list);

    Sort_Linked_List(linked_list);

    print_linked_list(linked_list);
}