// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

// You must implement a solution with O(1) time complexity for each function.

// Assumption: Methods pop, top and getMin operations will always be called on non-empty stacks.


// 1st Approach: Two Stacks

// The most straight forward way to solve this is using two stacks:
// Main Stack: Stores the actual values.
// Min Stack: Stores the minimum value encountered so far.

// When Pushing: Push the value onto the Main Stack. Compare the value with the top of the Min Stack. If the new value is smaller (or equal), push it onto the Min Stack as well.

// When Popping: Pop from the Main Stack. If the popped value is the same as the top of the Min Stack, pop from the Min Stack too. This means we are removing a minimum value, and the previous minimum will now be at the top of the Min Stack.

#include <iostream>
#include <stack>
#include <algorithm> // For std::min
#include<climits>

using namespace std;

class MinStack {
private:
    stack<int> s;       // Main stack to store all elements
    stack<int> min_s;   // Auxiliary stack to store minimums

public:
    MinStack() {
        // Constructor: nothing specific needed as stacks initialize empty by default
    }

    void push(int val) {
        s.push(val);
        
        // If min stack is empty OR the new value is smaller/equal to current min
        // push it onto the min stack.
        if (min_s.empty() || val <= min_s.top()) {
            min_s.push(val);
        }
    }

    void pop() {
        // If the top of the main stack is the current minimum,
        // we must remove it from the min_s as well.
        if (s.top() == min_s.top()) {
            min_s.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
};


// 2nd Approach
// It is more space efficient

class Min_Stack{
    public:
    stack<long long int> st;
       long long int min;
       Min_Stack(){
           this->min = INT_MAX;
       }

      void push(int val) {
          if(this->st.empty()) {
              this->min = val;
              this->st.push(val);
          } else {
              this->st.push(val-this->min);
              if(this->min > val) {
                  this->min = val;
              }
          }
      }

      void pop(){
        if(!this->st.empty()){
            if(this->st.top()>=0){
                this->st.pop();
            }
            else{
                this->min=this->min - this->st.top();
                this->st.pop();
            }
        }
      }

      int top(){
        if(this->st.size()==1){
            return this->st.top();
        }
        else if(this->st.top()<0){
            return this->min;
        }
        else{
            return this->min + this->st.top();
        }
      }

      int getMin(){
            return this->min;
      }
};

int main() {
    // MinStack* obj = new MinStack();
    Min_Stack* obj = new Min_Stack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    
    std::cout << "Minimum is: " << obj->getMin() << std::endl; // Returns -3
    
    obj->pop(); // Removes -3
    
    std::cout << "Top is: " << obj->top() << std::endl;       // Returns 0
    std::cout << "Minimum is: " << obj->getMin() << std::endl; // Returns -2
    
    return 0;
}