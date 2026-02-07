// Bucket Sort 
// It is based on scatter & gather approach
// It is specialy used to sort floating numbers

// This is used for all range of floating numbers
// Because in this code first we normalise the elements and then we start sorting

// It's a Stable Algorithm , if the sorting algorithm used for individual buckets is stable

// Input : { 6.13, 8.45, 0.12, 1.89, 4.75, 2.63, 7.85, 10.39 }
// Output : 0.12  1.89  2.63  4.75  6.13  7.85  8.45  10.39

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Bucket_sort(int n,float arr[]){

    // Create vector of vector
    vector<vector<float>> bucket(n,vector<float> ());

    // Finding range to normalize
    float min_element=arr[0];
    float max_element=arr[0];

    for(int i=1;i<n;i++){
        min_element=min(min_element,arr[i]);
        max_element=max(max_element,arr[i]);
    }

    float range=(max_element-min_element)/n;

    // Inserting elements into buckets
    for(int i=0;i<n;i++){
        int index=(arr[i]-min_element)/range;
        
        // for Boundary elements
        float diff=(arr[i]-min_element)/range - index;
        if(diff==0 && arr[i]!=min_element){
            bucket[index-1].push_back(arr[i]);
        }
        else{
            bucket[index].push_back(arr[i]);
        }
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
    // float arr[n] = { 6.13, 8.45, 0.12, 1.89, 4.75, 2.63, 7.85, 10.39 };
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