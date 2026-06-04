// Reverse a Stack

import java.util.Stack;

public class Stack_03 {
    // Helper function to insert an element at the bottom of the stack
    static void insertAtBottom(Stack<Integer> st, int item) {
        if (st.isEmpty()) {
            st.push(item);
            return;
        }
        
        int topElem = st.pop();
        insertAtBottom(st, item);
        st.push(topElem);
    }

    // Main function to reverse the stack
    static void reverseStack(Stack<Integer> st) {
        if (st.isEmpty()) {
            return;
        }
        
        int item = st.pop();
        reverseStack(st);
        insertAtBottom(st, item);
    }

    public static void main(String[] args){
        Stack<Integer> stack = new Stack<>();

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        System.out.println(stack);

        reverseStack(stack);

        System.out.println(stack);
    }
}
