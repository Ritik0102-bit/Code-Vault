// we want to do 2D Array Matrix Multiplication

#include<iostream>

using namespace std;

int main(){
    int r1,c1;
    cout << "Enter the row and column size of 1st Matrix";
    cin >> r1 >> c1;
    int arr1[r1][c1];
    cout << "Enter the elements of 1st Matrix ";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin >> arr1[i][j];
        }
    }
    
    int r2,c2;
    cout << "Enter the row and column size of 2nd Matrix";
    cin >> r2 >> c2;
    int arr2[r2][c2];
    cout << "Enter the elements of 2nd Matrix ";
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> arr2[i][j];
        }
    }
    
    if(c1!=r2){
        cout << "Matrix Multiply is not possible for this input.";
    }
    else{
        int multiply_array[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int value=0;
            for(int k=0;k<r2;k++){
                value+=arr1[i][k]*arr2[k][j];
            }
            multiply_array[i][j]=value;
        }
    }
    
    
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout << multiply_array[i][j] << "  ";
        }
        cout << endl;
    }
    }
}