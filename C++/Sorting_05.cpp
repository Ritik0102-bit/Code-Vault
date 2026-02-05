// Give an array of names of the fruits; you are supposed to sort it in lexicographical order using the selection sort

// Input : ["papaya","lime","watermelon","apple","mango","kiwi"]

// Output: ["apple","kiwi","lime","mango","papaya","watermelon"]

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void lexicographical_order(vector<string> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(v[min_index]>v[j]){
                min_index=j;
            }
        }
        if(min_index!=i){
            swap(v[i],v[min_index]);
        }
    }
    return ;
}

int main(){
    vector<string> v = {"papaya","lime","watermelon","apple","mango","kiwi"} ;

    lexicographical_order(v);

    for(int i=0;i<v.size();i++){
        cout << v[i] << "  ";
    }

    return 0;
}