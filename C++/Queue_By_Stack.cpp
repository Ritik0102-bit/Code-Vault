// We are given a stack data structure with push and pop operations, the task is to implement a queue using instances of stack data structure and operations on them.

// Implementation of Queue By Stack

// There are two ways of it :-

// Push efficient (enqueue) -> O(1) , pop (dequeue) can be bad
// Pop efficient (dequeue) -> O(1) , push (enqueue) can be bad

#include <iostream>
#include <stack>
using namespace std;

class Queue_Push_efficient {
    stack<int> st;
public:
    Queue_Push_efficient() {}

    // Enqueue
    // Time Complexity:- O(1)
    void push(int x) {
        this->st.push(x);
    }

    // Dequeue
    // Time Complexity:- O(n)
    void pop() { 
        if(this->st.empty()){
            return;
        }

        stack<int> tmp;
        while(this->st.size() > 1) {
            tmp.push(st.top());
            st.pop();
        }

        // now stack size is 1, and we are at the bottom element
        this->st.pop();
        while(not tmp.empty()) {
            this->st.push(tmp.top());
            tmp.pop();
        }
    }

    // Return the front element
    // Time Complexity:- O(n)
    int front() {
        if(this->st.empty()){
            return -1;
        }

        stack<int> tmp;
        while(this->st.size() > 1) {
            tmp.push(st.top());
            st.pop();
        }

        // now stack size is 1, and we are at the bottom element
        int result = this->st.top();
        while(not tmp.empty()) {
            this->st.push(tmp.top());
            tmp.pop();
        }

        return result;
    }

    bool is_empty(){
        return this->st.empty();
    }
};


class Queue_Pop_efficient {
    stack<int> st;
public:
    Queue_Pop_efficient() {}

    // Enqueue operation: O(N)
    // We want the newest element to be at the bottom of the stack
    // so that the oldest element remains at the top for O(1) pop.
    void push(int x) {
        stack<int> tmp;

        // 1. Move all existing elements from primary stack 'st' to temporary stack 'tmp'
        while (not this->st.empty()) {
            tmp.push(this->st.top());
            this->st.pop();
        }

        // 2. Push the new element onto the empty 'st'
        this->st.push(x);

        // 3. Move all elements back from 'tmp' to 'st'
        while (not tmp.empty()) {
            this->st.push(tmp.top());
            tmp.pop();
        }
    }

    // Dequeue operation: O(1)
    // The top of the stack is now the front of the queue
    void pop() {
        if (this->st.empty()) return;
        this->st.pop();
    }

    // Get front element: O(1)
    int front() {
        if (this->st.empty()) return -1;
        return this->st.top();
    }

    bool empty() {
        return this->st.empty();
    }
};

int main() {
    Queue_Push_efficient qu;
    qu.push(10); // Enqueue
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop(); // Dequeue

    while(not qu.is_empty()) {
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout << endl;
    
    Queue_Pop_efficient qu2;
    qu2.push(10); // Enqueue
    qu2.push(20);
    qu2.push(30);
    qu2.push(40);
    qu2.pop(); // Dequeue

    while(not qu2.empty()) {
        cout<<qu2.front()<<" ";
        qu2.pop();
    }
    cout << endl;

    return 0;
}








// Here is the explanation of **Amortized Complexity** followed by the optimized C++ code.

// ### Part 1: What is Amortized Complexity?

// **Amortized Complexity** is a way of calculating time complexity that looks at the "average" cost per operation over a sequence of many operations, rather than the worst-case cost of a single operation.

// Think of it like **paying rent**:

//   * **The Worst Case:** On the 1st of the month, you pay $3,000. That is a very expensive day\! (High cost).
//   * **The Best Case:** On days 2–30, you pay $0. (Low cost).
//   * **The Amortized Cost:** Even though you paid $3,000 on one day, if you spread that cost over the 30 days of the month, your **amortized cost** is effectively $100 per day.

// **Applying this to your Queue:**
// In your previous "Push Efficient" code, every time you did a `pop`, you moved elements back and forth. That was expensive every time.

// In the **Amortized** approach:

// 1.  We only move elements from `input` stack to `output` stack **when the output stack is empty**.
// 2.  Once we move them, they stay there. We don't move them back.
// 3.  This means the "heavy lifting" (moving $N$ elements) happens rarely. Most `pop` operations will just pick the top element off the `output` stack, which is instant.

// -----

// ### Part 2: The Amortized $O(1)$ Code

// Here is the industry-standard way to implement this. We use two stacks: `input` and `output`.

// ```cpp
// #include <iostream>
// #include <stack>
// using namespace std;

// class Queue_Amortized {
//     stack<int> input;  // Only for pushing
//     stack<int> output; // Only for popping/peeking

// public:
//     Queue_Amortized() {}

    // Push is always simply pushing to input stack
    // Time: O(1)
//     void push(int x) {
//         input.push(x);
//     }

    // Pop checks output stack first
    // Time: Amortized O(1)
//     void pop() {
//         if (output.empty()) {
            // If output is empty, we must transfer elements from input
            // This is the "expensive" step that happens rarely
//             while (!input.empty()) {
//                 output.push(input.top());
//                 input.pop();
//             }
//         }

        // If output is still empty after trying to transfer, the queue is empty
//         if (output.empty()) return; 
        
//         output.pop();
//     }

    // Front uses the same logic as pop
    // Time: Amortized O(1)
//     int front() {
//         if (output.empty()) {
//             while (!input.empty()) {
//                 output.push(input.top());
//                 input.pop();
//             }
//         }

//         if (output.empty()) return -1;

//         return output.top();
//     }

//     bool empty() {
        // Queue is empty only if BOTH stacks are empty
//         return input.empty() && output.empty();
//     }
// };

// int main() {
//     Queue_Amortized q;
//     q.push(1);
//     q.push(2);
//     q.push(3);

    // First pop will be "expensive" (moves 1, 2, 3 to output stack)
//     cout << "Front: " << q.front() << endl; 
//     q.pop(); 

    // Second pop will be cheap O(1) (2 is already sitting on top of output stack)
//     cout << "Front: " << q.front() << endl;
//     q.pop();

//     return 0;
// }
// ```

// ### Why is this $O(1)$?

// Let's trace the life of a single element (let's call it Number 5):

// 1.  **Push:** Number 5 is pushed onto `input`. (1 operation)
// 2.  **Move:** Eventually, Number 5 is popped from `input` and pushed to `output`. (2 operations)
// 3.  **Pop:** Finally, Number 5 is popped from `output` and returned to the user. (1 operation)

// **Total operations for Number 5:** 4 operations.
// Since every element is touched a constant number of times (exactly 4 times total in its life), the complexity is **Amortized Constant Time**, or **$O(1)$**.

// Would you like to try a practice problem involving Queues to test this concept?