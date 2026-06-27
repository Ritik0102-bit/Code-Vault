// We are given a stack data structure with push and pop operations, the task is to implement a queue using instances of stack data structure and operations on them.

// Implementation of Queue By Stack

// There are two ways of it :-

// Push efficient (enqueue) -> O(1) , pop (dequeue) can be bad
// Pop efficient (dequeue) -> O(1) , push (enqueue) can be bad


// 1st Approach
#include <iostream>
#include <stack>
using namespace std;

class Queue_Push_efficient {
    stack<int> st, tmp;

public:
    Queue_Push_efficient() {}

    // Enqueue: O(1)
    void push(int x) {
        st.push(x);
    }

    // Dequeue: O(N)
    void pop() { 
        if (st.empty()) return;

        // Move all but the last element to the temporary stack
        while (st.size() > 1) {
            tmp.push(st.top());
            st.pop();
        }

        // The remaining element is the oldest; pop it
        st.pop();

        // Move everything back to the primary stack
        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }
    }

    // Return the front element: O(N)
    int front() {
        if (st.empty()) return -1;

        while (st.size() > 1) {
            tmp.push(st.top());
            st.pop();
        }

        int result = st.top();

        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }

        return result;
    }

    bool empty() {
        return st.empty();
    }
};

// 2nd Approach
class Queue_Pop_efficient {
    stack<int> st, tmp;

public:
    Queue_Pop_efficient() {}

    // Enqueue: O(N)
    void push(int x) {
        // Move all existing elements to temporary stack
        while (!st.empty()) {
            tmp.push(st.top());
            st.pop();
        }

        // Push the new element to the bottom
        st.push(x);

        // Move all elements back on top of the new element
        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }
    }

    // Dequeue: O(1)
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    // Return front element: O(1)
    int front() {
        if (st.empty()) return -1;
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};

// 3rd Approach
class Queue_Amortized {
    stack<int> input;  // Used only for pushing
    stack<int> output; // Used only for popping/peeking

public:
    Queue_Amortized() {}

    // Enqueue: O(1)
    void push(int x) {
        input.push(x);
    }

    // Dequeue: Amortized O(1)
    void pop() {
        // If output is empty, transfer everything from input
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        // Pop from output
        if (!output.empty()) {
            output.pop();
        }
    }

    // Front: Amortized O(1)
    int front() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        if (output.empty()) return -1;
        
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};