// A critical point in a linked list is defined as either a local maxima or a local minima.

// Given a linked list tail, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points.

// If there are fewer than two critical points, return [-1, -1].

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int data)
    {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class Doubly_linked_list
{
public:
    Node *head;
    Node *tail;

    Doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_at_last(int data)
    {
        Node *new_node = new Node(data);

        if (tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    void print_Doubly_LL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

bool is_critical_point(Node *node)
{
    if (node->val < node->next->val && node->val < node->prev->val)
    {
        return true;
    }
    if (node->val > node->next->val && node->val > node->prev->val)
    {
        return true;
    }
    return false;
}

vector<int> min_max_distance(Node *head)
{
    if (head->next->next == NULL){
        return {-1, -1};
    }
    vector<int> ans = {-1, -1};

    Node *temp = head->next;
    int no_of_critical_points = 0;
    int idx = 0;
    int idx1 = -1;
    int idx2 = -1;
    while (temp->next != NULL){
        if (is_critical_point(temp)){
            no_of_critical_points++;
            if(no_of_critical_points == 1){
                idx1 = idx;
            }
            if(no_of_critical_points == 2){
                idx2 = idx;
                ans[0] = abs(idx1 - idx2);
                ans[1] = abs(idx1 - idx2);
            }
            
        }

        idx++;
        temp = temp->next;
    }

    if (no_of_critical_points < 2)
    {
        return {-1, -1};
    }
    return ans;
}

int main()
{
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
}