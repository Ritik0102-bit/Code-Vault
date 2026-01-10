// Given the head of a doubly linked list. The values of the linked list are sorted in non-decreasing order. Find if there exists a pair of distinct nodes such that the sum of their values is x. Return the pair in the form of a vector [l, r], where l and r are the values stored in the 2 nodes pointed by the pointers. If there are multiple such pairs, return any of them. If there is no such pair return [-1, -1].

// Target Pair Sum Question
// This will be solved by 2 Pointer Approach

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};


class Doubly_linked_list{
    public:
    Node* head;
    Node* tail;

    Doubly_linked_list(){
        head=NULL;
        tail=NULL;
    }

    void insert_at_last(int data){
        Node* new_node=new Node(data);

        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }

        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    }

    void print_Doubly_LL(){
        Node* temp=head;
        while(temp!=NULL){
            cout << temp->val << " -> ";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }

};

vector<int> pair_Sum_Doubly_LL(Node* head, Node* tail, int x){
    
    vector<int> ans(2,-1);
    while(head!=tail){
        int sum = head->val + tail->val;
        if(sum==x){
            ans[0]=head->val;
            ans[1]=tail->val;
            return ans;
        }
        
        if(sum>x){ // i need smaller values, i will move tail back
            tail=tail->prev;
        }
        else{ // i need bigger values, i will move head forward
            head=head->next;
        }
    }
    return ans;
}

int main(){
    Doubly_linked_list Doubly_LL;

    Doubly_LL.insert_at_last(1);
    Doubly_LL.insert_at_last(2);
    Doubly_LL.insert_at_last(3);
    Doubly_LL.insert_at_last(4);
    Doubly_LL.insert_at_last(5);
    Doubly_LL.insert_at_last(6);
    Doubly_LL.insert_at_last(7);
    Doubly_LL.insert_at_last(8);

    Doubly_LL.print_Doubly_LL();

    vector<int> ans=pair_Sum_Doubly_LL(Doubly_LL.head,Doubly_LL.tail,10);

    cout << "[ " << ans[0] << " , " << ans[1] << " ] ";
}