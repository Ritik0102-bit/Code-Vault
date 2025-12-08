// Implementation Of HashMap In Java

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Map.Entry;

class HashMap_Implementation<K,V>{
    private class Node{
        K key;
        V val;

        public Node(K key,V val){
            this.key=key;
            this.val=val;
        }
    }

    private int n; // No. of nodes in a Single Bucket (Linked List)
    private int N; // No. of Buckets
    private LinkedList<Node> Buckets[];

    @SuppressWarnings("unchecked")
    public HashMap_Implementation(){
        this.N=9; // Let's suppose we have 9 Buckets
        this.Buckets = new LinkedList[this.N];

        for(int i=0;i<N;i++){
            Buckets[i]=new LinkedList<>();
        }
    }

    private int Hash_Function(K key){
        int idx = key.hashCode();
        return Math.abs(idx) % N;
    }

    private int Search_In_LL(K key , int Buck_idx){
        LinkedList<Node> Bucket = Buckets[Buck_idx];

        for(int i=0;i<Bucket.size();i++){
            if(key==Bucket.get(i).key){
                return i;
            }
        }

        return -1;
    }

    @SuppressWarnings("unchecked")
    private void Rehash(){
        LinkedList<Node> Old_Buckets[] = Buckets;
        Buckets = new LinkedList[N*2]; // Double The No. of Buckets
        N = N * 2; // Update N

        for(int i=0;i<N*2;i++){
            Buckets[i] = new LinkedList<>();
        }

        n = 0; // Reset n, because put() will recalculate it

        for(int i=0;i<Old_Buckets.length;i++){
            LinkedList<Node> ll = Old_Buckets[i];
            for(int j=0;j<ll.size();j++){
                Node node = ll.get(j);
                put(node.key, node.val);
            }
        }
    }

    public void put(K key,V val){
        int Buck_idx = Hash_Function(key);
        int key_idx = Search_In_LL(key,Buck_idx);

        if(key_idx == -1){ // Key Doesn't Exist
            Buckets[Buck_idx].add(new Node(key, val));
            n++;
        }
        else{ //Key Already Exist
            Node node = Buckets[Buck_idx].get(key_idx);
            node.val=val;
        }

        double lambda = (double) n/N;

        if(lambda > 2.0){
            Rehash();
        }
    }

    public boolean contains_Key(K key){
        int Buck_idx=Hash_Function(key);
        int key_idx=Search_In_LL(key, Buck_idx);

        if(key_idx==-1){
            return false;
        }
        else{
            return true;
        }
    }

    public V Remove(K key){
        int Buck_idx=Hash_Function(key);
        int key_idx=Search_In_LL(key, Buck_idx);

        if(key_idx==-1){
            return null;
        }
        else{
            Node node = Buckets[Buck_idx].remove(key_idx);
            n--;
            return node.val;
        }
    }

    public V get(K key){
        int Buck_idx=Hash_Function(key);
        int key_idx=Search_In_LL(key, Buck_idx);

        if(key_idx==-1){
            return null;
        }
        else{
            Node node = Buckets[Buck_idx].get(key_idx);
            return node.val;
        }
    }


    public ArrayList<K> Key_Set(){
        ArrayList<K> keys = new ArrayList<>();

        for(int i=0;i<Buckets.length;i++){
            LinkedList<Node> ll=Buckets[i];
            for(int j=0;j<ll.size();j++){
                Node node = ll.get(j);
                keys.add(node.key);
            }
        }

        return keys;
    }

    public boolean isEmpty(){
        return n==0;
    }
}

public class HashMap_01 {
    public static void main(String[] args){
        HashMap_Implementation<String,Integer> map = new HashMap_Implementation<>();

        map.put("India", 50);
        map.put("China", 50);
        map.put("USA", 50);
        map.put("Russia", 50);
        map.put("India", 50);

        ArrayList<String> keys = map.Key_Set();
        for(int i=0;i<keys.size();i++){
            System.out.println(keys.get(i) + " " + map.get(keys.get(i)));
        }

        map.Remove("India");
        System.out.println(map.get("India"));
    }
}
