// Bubble Sort
// Continously swap the adjacent elements till it's in wrong order

// Maximum no. of swaps in worst Case = n(n-1)/2
// Time Complexity= O(n^2)

// Stable OR Unstable Sort ?
// Bubble Sort is a kind of Stable Sort
// Because If two elements have same value then their order in the array will not change

#include<iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int> &v){
    for(int i=0;i<v.size()-1;i++){
        for(int j=0;j<v.size()-1-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
    return ;
}

int main(){
    int n;
    cout << "Enter the no. of elements in the array : ";
    cin >> n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    bubble_sort(v);

    for(int i=0;i<n;i++){
        cout << v[i] << "  ";
    }
}