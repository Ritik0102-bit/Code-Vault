// Given an integer array arr, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Input:
// 0 5 0 3 4 2

// Output:
// 5 3 4 2 0 0

// 1st Method
// It is the best method to do this problem

#include<iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter the no. of elements: ";
    cin>> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }

    int c=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            c++;
        }
        else{
            arr[j++]=arr[i];
        }
    }

    for(int i=n-1;i>=n-c;i--){
        arr[i]=0;
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << "  ";
    }

    return 0;
}


// 2nd Method

// #include<iostream>
// #include<vector>

// using namespace std;

// void swap_zeroes(int n,vector<int> &v){
//     for(int i=n-1;i>=0;i--){
//         bool flag=false;
//         int j=0;
//         while(j!=i){
//             if(v[j]==0 && v[j+1]!=0){
//                 swap(v[j],v[j+1]);
//             }
//             j++;
//         }
//         if(!flag){ // If there will be no swap in this iteration so, there will be no zero left to arrange
//             break;
//         }
//     }
//     return;
// }

// int main(){
//     int n;
//     cout << "Enter the no. of elements: ";
//     cin>> n;

//     vector<int> v(n);
//     cout << "Enter the elements: ";
//     for(int i=0;i<n;i++){
//         cin>> v[i];
//     }

//     swap_zeroes(n,v);

//     for(int i=0;i<n;i++){
//         cout << v[i] << "  ";
//     }

//     return 0;
// }