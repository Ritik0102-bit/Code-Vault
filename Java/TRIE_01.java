// Word Break Problem
// Given an input string and a dictionary of words, find out if the input string can be broken into a space-separated sequence of dictionary words.

// words[ ] = { i, like, sam, samsung, mobile, ice}
// key = "ilikesamsung"

// output : true

public class TRIE_01 {
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

    public static boolean Word_Break(String word){
        if(word.length()==0){
            return true;
        }

        for(int i=1;i<=word.length();i++){
            String subString_1 = word.substring(0,i);
            String subString_2 = word.substring(i);

            if(Search_In_Trie(subString_1) && Word_Break(subString_2)){
                return true;
            }
        }

        return false;
    }


    public static void main(String[] args) {
        String[] Words = { "i", "like", "sam", "samsung", "mobile", "ice"};

        for(String word:Words){
            Insert_In_Trie(word);
        }

        System.out.println(Word_Break("ilikesamsung"));

    }
}
