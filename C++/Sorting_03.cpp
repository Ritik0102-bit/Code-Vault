// Insertion Sort
// Repeatedly take elements from unsorted subarray & insert in sorted subarray on it's correct position

// Time complexity in Worst Case = O(n^2)
// Time complexity in Best Case = O(n)

#include<iostream>
#include<vector>

using namespace std;

void Insertion_sort(int n,vector<int> &v){
    for(int i=1;i<n;i++){
        int current_element=v[i];
        // find correct position for current element
        int j=i-1;
        while(j>=0 && v[j]>current_element){
            v[j+1]=v[j];
            j--;
        }
        // Insert current Element
        v[j+1]=current_element;
    }
    return ;
}

int main(){
    int n;
    cout << "Enter the no. of elements in the array: ";
    cin>> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>> v[i];
    }

    Insertion_sort(n,v);

    for(int i=0;i<n;i++){
        cout << v[i]  << "  ";
    }
}