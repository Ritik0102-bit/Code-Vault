// Given an array of length n and a target, return a pair whose sum is equal to the target. If there is no pair present, return -1.

// Input 1: n = 7 
// Elements = [1, 4, 5, 11, 13, 10, 2] Target = 13
// Output 1: [11, 3]

// Input 2: n = 5 
// Elements = [9, 10, 2, 3, 5] Target = 15
// Output 2: [10, 5]

// Solution: https://pastebin.com/gTw2MVvu

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> Pair_Sum(vector<int> v,int target_sum){
    unordered_map<int,int> m;

    vector<int> ans={-1,-1};

    for(int i=0;i<v.size();i++){
        if(m.find(target_sum - v[i])!=m.end()){
            ans[0]=target_sum-v[i];
            ans[1]=v[i];
            return ans;
        }
        else{
            m[v[i]]=i;
        }
    }

    return ans;
}

int main(){
    vector<int> v={2,12,4,17,9,4,1,15,25};

    vector<int> ans=Pair_Sum(v,26);

    cout << ans[0] << "  " << ans[1];

    return 0;
}