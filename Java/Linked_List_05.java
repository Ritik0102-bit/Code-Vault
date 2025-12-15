// Detecting Loop in a Linked List

class Linked_List {
    Node head;
    int size;

    class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public void Add_Last(int data) {
        size++;
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }
        
        Node curr = head;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = newNode;
    }

    public void Print_Linked_List() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " -> ");
            curr = curr.next;
        }
        System.out.println("NULL");
    }

    public boolean Detect_cycle(Node head){
        Node slow=head;
        Node fast=head;

        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;

            if(slow==fast){
                return true;
            }
        }

        return false;
    }
}

public class Linked_List_05 {
    public static void main(String[] args){
        Linked_List list = new Linked_List();

        list.Add_Last(0);
        list.Add_Last(1);
        list.Add_Last(2);
        list.Add_Last(3);
        list.Add_Last(4);
        list.Add_Last(5);

        list.Print_Linked_List();

        System.out.println(list.Detect_cycle(list.head));
    }
}
