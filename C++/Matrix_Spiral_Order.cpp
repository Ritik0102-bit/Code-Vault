// we need to print the matrix in the spiral order
// for that we are making a direction variable 

// if direction=0
// then we print left to right

// if direction=1
// then we print top to bottom

// if direction=2
// then we print right to left

// if direction=3
// then we print bottom to top;

// and after that , this process will again start from direction = 0

// Input 
// 1 2 3
// 4 5 6
// 7 8 9

// Output
// 1 2 3 6 9 8 7 4 5

#include<iostream>
#include<vector>

using namespace std;

void Spiral_Order_Matrix(vector<vector<int>>&Matrix){
    int top=0;
    int bottom=Matrix.size()-1;
    int left=0;
    int right=Matrix[0].size()-1;

    int direction=0;

    while(left<=right && top<=bottom){

        // left --> right
        if(direction==0){
            for(int i=left;i<=right;i++){
                cout << Matrix[top][i] << "  ";
            }
            top++;
        }

        // top --> bottom
        else if(direction==1){
            for(int i=top;i<=bottom;i++){
                cout << Matrix[i][right] << "  ";
            }
            right--;
        }

        // right --> left
        else if(direction==2){
            for(int i=right;i>=left;i--){
                cout << Matrix[bottom][i] << "  ";
            }
            bottom--;
        }

        // bottom --> top
        else{
            for(int i=bottom;i>=top;i--){
                cout << Matrix[i][left] << "  ";
            }
            left++;
        }

        // direction needs to be changed after every loop
        // and it should lie between 0 to 3 only
        direction=(direction+1)%4;
    }
}

int main(){
    int n,m;
    cout << "Enter the row & column size of the Matrix : ";
    cin >> n >> m;

    vector<vector<int>> Matrix(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Matrix[i][j];
        }
    }

    Spiral_Order_Matrix(Matrix);
}