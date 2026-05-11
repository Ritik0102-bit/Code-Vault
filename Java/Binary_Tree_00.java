public class Binary_Tree_00 {

    static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    static class Binary_Tree {
        int idx = -1;

        // Build Tree from given Preorder Sequence
        public Node Build_Tree(int[] Preorder) {
            idx++;

            if (Preorder[idx] == -1) {
                return null;
            }

            Node new_Node = new Node(Preorder[idx]);
            new_Node.left = Build_Tree(Preorder);
            new_Node.right = Build_Tree(Preorder);

            return new_Node;
        }

        // Preorder_Traversal
        public void Preorder_Traversal(Node Root) {
            if (Root == null) {
                return;
            }

            System.out.print(Root.data + " ");
            Preorder_Traversal(Root.left);
            Preorder_Traversal(Root.right);
        }

        // Inorder_Traversal
        public void Inorder_Traversal(Node Root) {
            if (Root == null) {
                return;
            }

            Preorder_Traversal(Root.left);
            System.out.print(Root.data + " ");
            Preorder_Traversal(Root.right);
        }

        // Postorder_Traversal
        public void Postorder_Traversal(Node Root) {
            if (Root == null) {
                return;
            }

            Preorder_Traversal(Root.left);
            Preorder_Traversal(Root.right);
            System.out.print(Root.data + " ");
        }
    }

    public static void main(String[] args) {
        int[] Preorder = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

        Binary_Tree tree = new Binary_Tree();

        Node Root = tree.Build_Tree(Preorder);

        System.out.println(Root.data);

        System.out.println("Preorder_Traversal: ");
        tree.Preorder_Traversal(Root);
        System.out.println();

        System.out.println("Inorder_Traversal: ");
        tree.Inorder_Traversal(Root);
        System.out.println();

        System.out.println("Postorder_Traversal: ");
        tree.Postorder_Traversal(Root);
        System.out.println();
    }
}
