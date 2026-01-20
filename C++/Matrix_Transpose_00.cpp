// 1st Method
// In this method we are creating a new transpose matrix

#include<iostream>

using namespace std;

int main(){
    int r,c;
    cout << "Enter the size of the Matrix ";
    cin >> r >> c;
    
    int arr[r][c];
    cout << "Enter the elements of the Matrix ";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    
    int transpose[c][r];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            transpose[i][j]=arr[j][i];
        }
    }
    
    cout << "Transpose of the Matrix : " ;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout <<  transpose[i][j] << "  ";
        }
        cout << endl;
    }
}