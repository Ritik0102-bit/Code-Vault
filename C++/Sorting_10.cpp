// Bucket Sort 
// It is based on scatter & gather approach
// It is specialy used to sort floating numbers

// This is only used to sort the numbers range between 0 to 1 only

// It's a Stable Algorithm , if the sorting algorithm used for individual buckets is stable

// Input : { 0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 0.39 }
// Output : 0.12  0.13  0.39  0.45  0.63  0.75  0.85  0.89 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Bucket_sort(int n,float arr[]){
    // Create vector of vector
    vector<vector<float>> bucket(n,vector<float> ());

    // Inserting elements into buckets
    for(int i=0;i<n;i++){
        int index=arr[i]*n;
        bucket[index].push_back(arr[i]);
    }

    // sorting elements in the buckets
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    // Inserting sorted elements into original array
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }

    return;

}

int main(){
    int n;
    cout << "Enter the no. of elements: ";
    cin>> n;

    float arr[n];
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    Bucket_sort(n,arr);

    for(int i=0;i<n;i++){
        cout << arr[i] << "  ";
    }

    return 0;
}