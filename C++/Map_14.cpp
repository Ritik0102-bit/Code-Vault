// You are given an integer n (number of elements). Then n elements are given. You must return the sum of repetitive elements (elements appearing more than once).

// Input:

// n = 7

// Elements = [1, 1, 2, 1, 3, 3, 3]

// Output: 4

// Explanation: The repetitive elements are 1 and 3. Sum = 1 + 3 = 4.

// Solution Link: https://pastebin.com/y2knju5m

#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int arr[]= {1, 1, 2, 1, 3, 3, 3 , 3};

    unordered_map<int,int> m;

    for(int i=0;i<8;i++){
        m[arr[i]]++;
    }

    int sum=0;

    for(auto ele:m){
        if(ele.second>1){
            sum+=ele.first;
        }
    }

    cout << sum;

    return 0;
}