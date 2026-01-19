// 1st Method
// It's a Brute force method
// In this code we need to find the sum of the matrix formed between two coordinates
// (r1,c1) & (r2,c2)

// Input:
// 1 2 3
// 4 5 6
// 7 8 9
// r1:1    c1:1
// r2:2    c2:2

// Output:
// 28

#include<iostream>

using namespace std;

int main(){
    int n,m;
    cout << "Enter the dimensions of the Matrix: ";
    cin >> n >> m;

    int arr[n][m];

    cout << "Enter the elements of the matrix : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    int r1,c1,r2,c2;

    cout << "Enter the value of r1: ";
    cin >> r1;
    cout << "Enter the value of c1: ";
    cin >> c1;
    cout << "Enter the value of r2: ";
    cin >> r2;
    cout << "Enter the value of c2: ";
    cin >> c2;

    int sum=0;

    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            sum+=arr[i][j];
        }
    }

    cout << "The sum of the matrix formed by (r1,c1) & (r2,c2) : " << sum ;
}