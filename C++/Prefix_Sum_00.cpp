// Prefix Sum -> Row Wise
// In this code we are going to calculate every element as the sum of previous elements in a row

// Input:
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 1  3  6  
// 4  9  15
// 7  15  24

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cout << "Enter the dimensions of the 2D Array: ";
    cin >> n >> m;

    vector<vector<int>> Vect(n,vector<int>(m));

    cout << "Enter the elements of the 2D Array : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Vect[i][j];
        }
    }

    // Prefix Sum --> Row wise
    for(int i=0;i<Vect.size();i++){
        for(int j=1;j<Vect[i].size();j++){
            Vect[i][j]+=Vect[i][j-1];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << Vect[i][j] << "  ";
        }
        cout << endl;
    }
}