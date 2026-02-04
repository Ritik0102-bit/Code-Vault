// Bubble Sort
// It is a omtimized BUBBLE SORT
// If there is a nearly sorted array

// If the array is sorted in just one pass so, we will break in next pass

#include<iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int> &v){
    for(int i=0;i<v.size()-1;i++){
        bool flag = false;
        for(int j=0;j<v.size()-1-i;j++){
            if(v[j]>v[j+1]){
                flag=true;
                swap(v[j],v[j+1]);
            }
        }
        if(!flag){
            break;
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