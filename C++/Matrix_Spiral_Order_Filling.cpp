// In this we are going to fill the matrix in the Spiral Order

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> Create_Spiral_order(int n){

    vector<vector<int>> Matrix(n,vector<int>(n));
    
    int left=0;
    int right=n-1;
    int top=0;
    int bottom=n-1;

    int direction=0;
    int value=1;

    while(left<=right && top<=bottom){
        if(direction==0){
            for(int i=left;i<=right;i++){
                Matrix[top][i]=value++;
            }
            top++;
        }

        else if(direction==1){
            for(int i=top;i<=bottom;i++){
                Matrix[i][right]=value++;
            }
            right--;
        }

        else if(direction==2){
            for(int i=right;i>=left;i--){
                Matrix[bottom][i]=value++;
            }
            bottom--;
        }

        else{
            for(int i=bottom;i>=top;i--){
                Matrix[i][left]=value++;
            }
            left++;
        }

        direction=(direction+1)%4;
    }

    return Matrix;
}

int main(){
    int n;
    cout << "Enter the dimension of the matrix : ";
    cin >> n;

    vector<vector<int>> V(n,vector<int>(n));

    V=Create_Spiral_order(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << V[i][j] << "  ";
        }
        cout << endl;
    }
}