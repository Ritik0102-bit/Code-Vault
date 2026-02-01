// In this code we are trying to calculate no. of possible paths from one position to the last position in a GRID

// let 3x3 GRID
// then we need to find no. of possible paths from a00 to a22
// And we can only move in right or downward direction

// Time Complexity : O(n!)
// This is a worst Time Complexity

// 1st Approach

#include<iostream>

using namespace std;

int Grid_path(int i,int j,int m,int n){
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(i>=m || j>=n){
        return 0;
    }
    return Grid_path(i,j+1,m,n) + Grid_path(i+1,j,m,n);
}

int main(){
    cout << Grid_path(0,0,4,6);

    return 0;
}



// 2nd Approach 
// In this we are just taking 2 inputs in place of 4 inputs

#include<iostream>

using namespace std;

int Grid_path(int m,int n){
    if(m==0 && n==0){
        return 1;
    }
    if(m<0 || n<0){
        return 0;
    }
    return Grid_path(m-1,n) + Grid_path(m,n-1);
}

int main(){
    cout << Grid_path(3-1,3-1);

    return 0;
}


// 3rd Approach 
// This is the best approach to do this problem 

// In this approach we will fill 1 in the last row and last column and then we start fill the numbers till arr[0,0]
// we are filling numbers in such a way that it is the sum of corresponding row & column elements
