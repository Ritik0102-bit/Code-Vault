// Stack Implementation in Java (Collection Framework)

import java.util.Stack;

public class Stack_01 {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        
        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Top element: " + stack.peek()); // Output: 30

        System.out.println("Popped element: " + stack.pop()); // Output: 30
        System.out.println("Top element after pop: " + stack.peek()); // Output: 20
    }
}
