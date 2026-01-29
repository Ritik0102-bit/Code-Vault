#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr,int start,int end){
    int idx=start-1;
    int pivot_element=arr[end];

    for(int j=start;j<end;j++){
        if(arr[j]<pivot_element){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }

    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}

void Quick_Sort(vector<int> &arr,int start,int end){
    if(start<end){
        int pivot_idx=partition(arr,start,end);

        Quick_Sort(arr,start,pivot_idx-1);
        Quick_Sort(arr,pivot_idx+1,end);
    }
}

int main(){
    vector<int> arr={1,4,2,1,2,3,5,9};

    Quick_Sort(arr,0,7);

    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }

    return 0;
}