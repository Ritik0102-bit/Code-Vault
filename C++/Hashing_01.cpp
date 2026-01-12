// Implement Hash Table using closed Addressing

#include<iostream>
#include<vector>
#include<list> // linked list implenetation In STL
#include<algorithm>

using namespace std;

class Hash_Table{
    vector<list<int>> Hashtable;
    int buckets;

    public:

    Hash_Table(int size){
        buckets=size;
        Hashtable.resize(size);
    }

    int hash_value(int key){
        return key % buckets;  // Division Method
    }

    void Add_element(int ele){
        int idx= hash_value(ele);
        Hashtable[idx].push_back(ele);
    }

    list<int>::iterator searchKey(int key){
        int idx = hash_value(key);
        return find(Hashtable[idx].begin(), Hashtable[idx].end(), key);
    }

    void deleteKey(int key){

        int idx = hash_value(key);
        if(searchKey(key)!= Hashtable[idx].end()){ //key is present
            Hashtable[idx].erase(searchKey(key));
            cout<<key<<" is deleted"<<endl;
        }
        else{
            cout << "Key is not present inside the hashtable";
        }
    }
};

int main(){
    Hash_Table HT(10);

    HT.Add_element(1);
    HT.Add_element(2);
    HT.Add_element(3);
    HT.Add_element(4);

    HT.deleteKey(3);
    HT.deleteKey(3);

    return 0;
}