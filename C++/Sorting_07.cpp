// Quick Sort
// It's based on Divide & Conquer algorithm

// In this sorting algorithm we are taking one pivot element from the array and arranging it in it's correct position
// we will find elements which are less than pivot element and putting them in the first place 
// And after that the pivot element and after that elements which are greater than pivot element

// It's a Unstable sorting algorithm


// Time Complexity:
// Best and Average Case: O(nlogn). This occurs when the pivot element divides the array into two roughly equal halves in each step.
// Worst Case: O(n^2). This happens when the pivot is always the smallest or largest element (e.g., when sorting an already sorted array). This leads to highly unbalanced partitions.

// Space Complexity: O(logn) on average, for the recursion stack space. The worst-case space complexity is O(n).

#include<iostream>

using namespace std;

int partition(int arr[],int first,int last){
    int pivot_element=arr[last];
    int i=first-1; // for inserting elements < pivot
    int j=first; // for finding elements < pivot

    for(int j=first;j<last;j++){
        if(arr[j]<pivot_element){
            swap(arr[++i],arr[j]);
        }
    }

    // Now i is pointing to the last element < pivot
    // correct position for pivot will be -> i+1
    swap(arr[i+1],arr[last]);
    return i+1;
}

void quick_sort(int arr[],int first,int last){
    // Base Case
    if(first>=last){
        return ;
    }
    int pivot_index=partition(arr,first,last);
    // Recusive Case
    quick_sort(arr,first,pivot_index-1);
    quick_sort(arr,pivot_index+1,last);
}

int main(){
    int n;
    cout << "Enter the no. of elements in the array: ";
    cin>> n;

    int arr[n] ;
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }

    quick_sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i]  << "  ";
    }
}