// Count Unique Substrings
// Given a string of length n of lowercase alphabet characters, we need to count total number of distinct substrings of this string.

// str = "ababa"
// ans = 10

// In this Question we will use the approach that 
// First we will insert all suffix of that word
// And then we will count all the prefix in that Trie (Which is equal to count of Nodes In Trie)

public class TRIE_03 {
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

    public static void Suffix(String Word){
        for(int i=0;i<Word.length();i++){
            Insert_In_Trie(Word.substring(i));
        }
    }

    public static int Count_Nodes(Node root){
        if(root==null){
            return 0;
        }

        int count=0;

        for(int i=0;i<26;i++){
            if(root.children[i]!=null){
                count+=Count_Nodes(root.children[i]);
            }
        }

        return count+1;
    }

    public static int Count_Unique_SubStrings(String Word){
        Suffix(Word);

        return Count_Nodes(Root);
    }


    public static void main(String[] args) {
        String Word = "ababa";

        System.out.println(Count_Unique_SubStrings(Word));

    }
}
