// we need to find row no. of which is having maximum no. of 1
// Input:
// 0 1 1 1 
// 0 0 0 1
// 0 0 1 1
// output: 0th row

#include<iostream>
#include<vector>
#include<climits> // this includes INT_MIN

using namespace std;

int find_max_ones(int rows,int columns,vector<vector<int>> &V){
    int max_ones=INT_MIN;
    int max_ones_row=-1;
    
    for(int i=0;i<rows;i++){
        int count=0;
        for(int j=0;j<columns;j++){
            if(V[i][j]==1){
                count++;
            }
        }
        if(count>max_ones){
            max_ones=count;
            max_ones_row=i;
        }
    }
    return max_ones_row;
}

int main(){
    int n,m;
    cout << "Enter the dimensions of 2D vector: ";
    cin >> n >> m;

    vector<vector<int>> V(n,vector<int>(m));

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> V[i][j];
        }
    }

    cout << "Index of row with maximum 1: " << find_max_ones(n,m,V);
}