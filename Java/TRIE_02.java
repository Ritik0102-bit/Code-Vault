// startsWith Problem
// Create a function boolean startsWith(String prefix) for a trie.
// Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

// words[ ] = { "apple", "app", "mango", "man", "woman" }

// prefix = "app"      output : true

// prefix = "moon"     output : false

public class TRIE_02 {
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

    public static boolean StartsWith(String key){
        Node curr = Root;

        for(int i=0;i<key.length();i++){
            int idx=key.charAt(i) - 'a';

            if(curr.children[idx] == null){
                return false;
            }

            curr=curr.children[idx];
        }

        return true;
    }


    public static void main(String[] args) {
        String[] Words = { "apple", "app", "mango", "man", "woman" };

        for(String word:Words){
            Insert_In_Trie(word);
        }

        System.out.println(StartsWith("app"));
        System.out.println(StartsWith("moon"));

    }
}
