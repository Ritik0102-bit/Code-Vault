// Find the nth node from the end & remove it.

class Linked_List{
    Node head;

    class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
            this.next=null;
        }
    }

    public void Add(int val){
        Node new_Node=new Node(val);

        if(head==null){
            head=new_Node;
            return;
        }

        Node curr=head;
        while(curr.next!=null){
            curr=curr.next;
        }

        curr.next=new_Node;
        return;
    }

    public void Print_List(){
        Node curr=head;
        while(curr!=null){
            System.out.print(curr.data + " -> ");
            curr=curr.next;
        }
        System.out.println("NULL");
    }

    public Node Remove_nth_from_end(Node head,int n){
        if(head==null || head.next==null){
            head=null;
            return head;
        }

        Node slow=head;
        Node fast=head;

        while(n>0){
            fast=fast.next;
            n--;
        }

        // If fast is null after moving n steps, 
        // it means we need to remove the head node itself.
        if (fast == null) {
            return head.next;
        }

        while(fast.next!=null){
            slow=slow.next;
            fast=fast.next;
        }

        slow.next=slow.next.next;

        return head;
    }
}


public class Linked_List_03 {
    public static void main(String[] args){
        Linked_List list=new Linked_List();

        list.Add(0);
        list.Add(1);
        list.Add(2);
        list.Add(3);
        list.Add(4);
        list.Add(5);

        list.Print_List();

        list.head = list.Remove_nth_from_end(list.head,3);

        list.Print_List();
    }
}
