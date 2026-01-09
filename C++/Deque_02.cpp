// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window which basically contains the max element in each window.

// LeetCode -> Maximum Sliding Window Problem

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> max_sliding_window(vector<int> &arr,int k){
    vector<int> res; 
    // we are storing index in this deque
    deque<int> dq;

    for(int i=0;i<k;i++){
        while(!dq.empty()  && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    
    for(int i=k;i<arr.size();i++){
        if(dq.front()==i-k){
            dq.pop_front();
        }
        while(!dq.empty()  && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }

    return res;
}

int main(){
    vector<int> v={1,2,3,4,5,7,8,9};
    int k=3;

    vector<int> result = max_sliding_window(v,k);

    for(int n:result){
        cout << n << " ";
    }

    return 0;
}