// Count Sort
// It's a Stable sorting algorithm

// The logic behind the count sort is that we will select any element from the array and Place it on the (No. of elements lesser than this elements )  index
// Example : [2,1,3,2,4]
// So, in this array correct position of 3 is at index 3 because there are 3 elements lesser than 3

#include<iostream>

using namespace std;

void count_sort(int n,int arr[]){

    int max=INT8_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    // Frequency array
    int freq[max+1]={0}; //Initializing all elements to zero
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    // Now we need to calculate cumulative frequency
    for(int i=1;i<=max;i++){
        freq[i]+=freq[i-1];
    }

    // Now we will insert 
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }

    return;
}

int main(){
    int n;
    cout << "Enter the no. of elements in the array: ";
    cin>>n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }

    count_sort(n,arr);

    for(int i=0;i<n;i++){
        cout << arr[i] << "  ";
    }

    return 0;
}