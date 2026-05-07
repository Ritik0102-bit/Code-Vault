// Trie : Implementations, Insert & Search 

public class TRIE_00 {
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

    public static boolean Search_In_Trie(String key){
        Node curr = Root;

        for(int i=0;i<key.length();i++){
            int idx=key.charAt(i) - 'a';

            if(curr.children[idx] == null){
                return false;
            }

            curr=curr.children[idx];
        }

        if(curr.EOW == false){
            return false;
        }

        return true;
    }


    public static void main(String[] args) {
        String[] Words = {"the", "a", "there", "their", "any", "thee"};

        for(String word:Words){
            Insert_In_Trie(word);
        }

        System.out.println("thee -> " + Search_In_Trie("thee"));
        System.out.println("thor -> " + Search_In_Trie("thor"));

    }
}
