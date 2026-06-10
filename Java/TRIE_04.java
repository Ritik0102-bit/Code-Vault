// Longest Word with all Prefixes
// Find the longest string in words such that every prefix of it is also in words.

// words = [“a”, “banana”, “app”, “appl”, “ap”, “apply”, “apple”]

// ans = "apple"

public class TRIE_04 {
    static class Node{
        Node[] children = new Node[26];
        boolean EOW;

        Node(){
            for(int i=0;i<26;i++){
                children[i]=null;
            }
            EOW=false;
        }
    }

    public static Node Root = new Node();

    public static void Insert_In_Trie(String Word){
        Node curr = Root;

        for(int i=0;i<Word.length();i++){
            int idx = Word.charAt(i) - 'a';
            
            if(curr.children[idx]==null){
                curr.children[idx] = new Node();
            }

            curr=curr.children[idx];
        }
        curr.EOW=true;
    }

    public static String ans = "";

    public static void Longest_Word(Node root,StringBuilder temp){
        for(int i=0;i<26;i++){
            if(root.children[i]!=null && root.children[i].EOW==true){
                temp.append((char) (i+'a'));
                if(temp.length()>ans.length()){
                    ans=temp.toString();
                }

                Longest_Word(root.children[i],temp);

                temp.deleteCharAt(temp.length()-1); // Backtracking
            }
        }
    }


    public static void main(String[] args) {
        String[] Words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

        for(String word:Words){
            Insert_In_Trie(word);
        }

        Longest_Word(Root, new StringBuilder(""));

        System.out.println(ans);

    }
}

