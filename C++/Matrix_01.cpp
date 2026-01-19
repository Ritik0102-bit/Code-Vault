// 2nd Method
// It's a efficient method
// we need to find the sum of the matrix formed between two coordinates (r1,c1) & (r2,c2)

// we are using the prefix sum method to find the sum faster

#include<iostream>
#include<vector>

using namespace std;

int Sum_of_Matrix(int r1,int c1,int r2,int c2,vector<vector<int>> &Matrix){
    int sum=0;

    // Prefix Sum --> Row wise
    for(int i=0;i<Matrix.size();i++){
        for(int j=1;j<Matrix[i].size();j++){
            Matrix[i][j]+=Matrix[i][j-1];
        }
    }

    for(int i=r1;i<=r2;i++){
        if(r1!=0){
            sum+=Matrix[i][c2]-Matrix[i][c1-1];
        }
        else{
            // Matrix[i][c1-1]=0
            sum+=Matrix[i][c2];
        }
    }

    return sum;

}

int main(){
    int n,m;
    cout << "Enter the dimensions of the matrix: ";
    cin >> n >> m;

    vector<vector<int>> Matrix(n,vector<int>(m));

    cout << "Enter the elemnts of the matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> Matrix[i][j];
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

    int sum;

    sum=Sum_of_Matrix(r1,c1,r2,c2,Matrix);

    cout << "The sum of the matrix formed by (r1,c1) & (r2,c2) : " << sum ;

}