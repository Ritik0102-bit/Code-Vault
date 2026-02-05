// Selection Sort
// Repeatedly find the minimum element in the unsorted array & place it at begining

// Maximum no. of swaps = n-1
// Time Complexity= O(n^2)

// It's a Unstable Sort

#include<iostream>
#include<vector>

using namespace std;

void Selection_sort(int n,vector<int> &v){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[min_index]){
                min_index=j;
            }
        }
        if(i!=min_index){
            int temp=v[min_index];
            v[min_index]=v[i];
            v[i]=temp;
        }
    }
    return;
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

    Selection_sort(n,v);

    for(int i=0;i<n;i++){
        cout << v[i] << "  ";
    }
}