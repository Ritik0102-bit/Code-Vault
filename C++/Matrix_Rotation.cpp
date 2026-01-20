// You are given an NxN matrix, where N is an even integer. Your task is to perform a layered 90-degree clockwise rotation of each concentric "layer" of the matrix. Starting from the outermost layer, rotate each layer clockwise by 90 degrees, and repeat for each subsequent inner layer until the innermost layer is reached. The innermost elements of the matrix (if only one central element exists) should remain unchanged. You are required to perform this rotation in place without using additional memory for temporary storage.

// Input Format

// An integer N representing the dimensions of the matrix (2 ≤ N ≤ 1000; always even).

// A 2D array M of dimensions N x N, where each element is an integer (-10^5 ≤ M[i][j] ≤ 10^5).

// Constraints

// 2≤N≤1000, where

// N is always an even integer. Matrix M is an N x N matrix. Each element in M is an integer: − 1 0 5 ≤ 𝑀 [ 𝑖 ] [ 𝑗 ] ≤ 1 0 5 −10 5 ≤M[i][j]≤10 5 . Rotation should be performed in place, without additional memory for storage.

// Output Format

// The matrix after performing the layered 90-degree clockwise rotation on each concentric layer.

// Sample Input 0
// 2
// 42 17
// 99 23

// Sample Output 0
// 99 42
// 23 17


// Sample Input 1
// 3
// 1 2 3
// 4 5 6
// 7 8 9

// Sample Output 1
// 7 4 1
// 8 5 2
// 9 6 3


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cout << "Enter the dimension of the matrix : ";
    cin >> n;

    vector<vector<int>> Matrix(n,vector<int>(n));

    cout << "Enter the elments of the matrix : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Matrix[i][j];
        }
    }
    
    // for 90 degree rotation 
    // we need to first take transpose and then we need to reverse each row
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){ // we only need to swap upper triangular part of matrix 
            // because if we swap all the elements then it will come again as original matrix
            swap(Matrix[i][j],Matrix[j][i]); 
        }
    }
    
    for(int i=0;i<n;i++){
        reverse(Matrix[i].begin(),Matrix[i].end());
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}