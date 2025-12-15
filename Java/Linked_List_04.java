// Check if a Linked List is a palindrome

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

    public Node Reverse(Node head){
        Node prev=head;
        Node curr=prev.next;

        while (curr!=null) {
            Node next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;            
        }

        head.next=null;
        return prev;
    }

    public Node getMiddleNode(Node head){
        Node slow = head;
        Node fast = head;

        while(fast.next!=null && fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }

        return slow;
    }

    public boolean check_Palindrome(Node head){
        if(head==null || head.next==null){
            return true;
        }

        Node middle=getMiddleNode(head);
        Node new_head=Reverse(middle.next);

        while(new_head!=null){
            if(head.data!=new_head.data){
                return false;
            }
            new_head=new_head.next;
            head=head.next;
        }
        return true;
    }
}


public class Linked_List_04 {
    public static void main(String[] args){
        Linked_List list=new Linked_List();

        list.Add_Last(0);
        list.Add_Last(1);
        list.Add_Last(2);
        list.Add_Last(3);
        list.Add_Last(3);
        list.Add_Last(2);
        list.Add_Last(1);
        list.Add_Last(0);

        list.Print_Linked_List();

        System.out.println(list.check_Palindrome(list.head));
    }
}