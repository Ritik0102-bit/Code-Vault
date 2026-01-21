// 2nd Method
// it is a efficient method
// because we are doing changes in the same 2D vector

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cout << "Enter the dimensions of the Matrix : ";
    cin >> n >> m;

    vector<vector<int>> Matrix(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Matrix[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(Matrix[i][j],Matrix[j][i]);
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}