// Implementing Stack using ArrayList in Java

import java.util.ArrayList;

class Stack{
    ArrayList<Integer> stack;

    Stack(){
        stack=new ArrayList<>();
    }

    public void push(int val){
        stack.add(val);
    }

    public int pop(){
        if(stack.isEmpty()){
            System.out.println("Stack is empty!");
            return -1; // Return -1 to indicate stack is empty
        }
        return stack.remove(stack.size() - 1);
    }

    public int peek(){
        if(stack.isEmpty()){
            System.out.println("Stack is empty!");
            return -1; // Return -1 to indicate stack is empty
        }
        return stack.get(stack.size() - 1);
    }
}

public class Stack_00 {
    public static void main(String[] args){
        Stack stack=new Stack();

        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Top element: " + stack.peek()); // Output: 30

        System.out.println("Popped element: " + stack.pop()); // Output: 30
        System.out.println("Top element after pop: " + stack.peek()); // Output: 20
    }
}
