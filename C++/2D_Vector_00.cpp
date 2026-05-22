// 2 Dimensional vector 
// it is vector of vector datatype
// vector<vector<datatype>> V;

#include<iostream>
#include<vector>
#include<bits/stdc++.h> // It includes so many libraries

using namespace std;

int main(){
    int n;
    vector<int> v1={1,2,3};
    vector<int> v2={4,5};
    vector<int> v3={6,7};
    
    vector<vector<int>> V={v1,v2,v3};

    // how to initialize vector of size N x M
    int n=2;
    int m=3;
    vector<vector<int>> V4(n,vector<int> (m));

    // there n denotes no. of rows
    // there m denotes no. of columns
    vector<vector<int>> V5(n,vector<int> (m));

    // we are making vector of 3 x 4 with the default value as zero
    vector<vector<int>> V6(3,vector<int>(4,0));

    for(int i=0;i<V.size();i++){
        for(int j=0;j<V[i].size();j++){
            cout<< V[i][j];
        }
    }

}