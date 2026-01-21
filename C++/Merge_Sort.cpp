#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr,int start,int mid,int end){
    vector<int> v;

    int i=start;
    int j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            v.push_back(arr[i]);
            i++;
        }
        else{
            v.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        v.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        v.push_back(arr[j]);
        j++;
    }

    for(int i=0;i<v.size();i++){
        arr[i+start]=v[i];
    }
}

void Merge_Sort(vector<int> &arr,int start,int end){

    if(start>=end){
        return;
    }

    int mid=start + (end-start)/2;

    Merge_Sort(arr,start,mid);
    Merge_Sort(arr,mid+1,end);

    merge(arr,start,mid,end);
}

int main(){
    vector<int> arr={1,4,2,1,2,3,5,9};

    Merge_Sort(arr,0,7);

    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }

    return 0;
}