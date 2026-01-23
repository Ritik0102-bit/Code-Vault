// 2nd Method
// we know that every element of pascal triangle can be find by nCr formula 
// where n is row no. & r is column no.
// nCr = n! / (r!)*(n-r)!

#include<iostream>
#include<vector>

using namespace std;

int nCr(int n,int r){
    int result=1;
    for(int i=n;i>0;i--){
        result*=i;
    }
    for(int i=r;i>0;i--){
        result/=i;
    }
    for(int i=(n-r);i>0;i--){
        result/=i;
    }
    return result;
}

void Pascal_Triangle(int n){
    vector<vector<int>> V(n,vector<int>(n));

    for(int i=0;i<n;i++){
        V[i].resize(i+1);
        for(int j=0;j<n;j++){
            V[i][j]=nCr(i,j);
        }
    }
    for(int i=0;i<V.size();i++){
        for(int j=0;j<V[i].size();j++){
            cout << V[i][j] << "  ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the no. of rows of the pascal triangle: ";
    cin >> n;
    
    Pascal_Triangle(n);
}