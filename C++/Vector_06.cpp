// check if we can partition the array into two subarrays with equal sum.
// More formally, check that the prefix sum of a part of the array is equal to the 
// suffix sum of rest of the array

#include<iostream>
#include<vector>

using namespace std;

bool check_partition_sum(vector<int> v,int &position){
    int total_sum=0;
    int prefix_sum=0;
    int suffix_sum;

    for(int i=0;i<v.size();i++){
        total_sum+=v[i];
    }
    for(int i=0;i<v.size();i++){
        suffix_sum=total_sum-prefix_sum;
        if(prefix_sum==suffix_sum){
            position=i;
            return true;
        }
        prefix_sum+=v[i];
    }
    return false;

}

int main(){
    int n;
    cout<< "Enter the size of array : ";
    cin>> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    int position=-1;
    if(check_partition_sum(v,position)){
        cout << "Subarrays with prefix_sum = suffix_sum is possible at" << position << endl;
    }
    else{
        cout << "No SubArrays are possible";
    }
    return 0;
}