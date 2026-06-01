// Implementing Queue using 2 Stack

// In this implementation add method takes O(n) & remove takes O(1)

import java.util.Stack;

public class Queue_04 {
    static class Queue {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();

        public boolean isEmpty() {
            return s1.isEmpty();
        }

        // O(n)
        public void add(int data) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
            s1.push(data);
            while (!s2.isEmpty()) {
                s1.push(s2.pop());
            }
        }

        // O(1)
        public int remove() {
            return s1.pop();
        }

        public int peek() {
            return s1.peek();
        }
    }

    public static void main(String args[]) {
        Queue q = new Queue();
        q.add(1);
        q.add(2);
        q.add(3);

        while (!q.isEmpty()) {
            System.out.println(q.peek());
            q.remove();
        }
    }
}
