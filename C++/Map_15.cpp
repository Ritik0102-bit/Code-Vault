// Given an array arr[] of length N, find the length of the longest subarray with a sum equal to 0.

// Input 1: n = 8 arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
// Output 1: 5

// Input 2: n = 3 arr[] = {1, 2, 3}
// Output 2: 0

// Solution: https://pastebin.com/u7bB49de

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int len_of_longest_subarray_with_sum_zero(vector<int> v){
    unordered_map<int,int> m;

    int prefix_sum=0;
    int length=0;

    for(int i=0;i<v.size();i++){
        prefix_sum+=v[i];

        if(m.find(prefix_sum)!=m.end()){
            length=max(length,i-m[prefix_sum]);
        }
        else{
            m[prefix_sum]=i;
        }
    }

    return length;
}

int main(){
    int n=8;

    vector<int> v = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << len_of_longest_subarray_with_sum_zero(v) << endl;
    
    return 0;
}