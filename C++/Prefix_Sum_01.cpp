// Prefix Sum -> Column Wise
// In this code we are going to calculate every element as the sum of previous elements in a column

// Input:
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
//  1  2   3  
//  5  7   9
// 12  15  18

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

    // Prefix Sum --> Column wise
    for(int i=1;i<Vect.size();i++){
        for(int j=0;j<Vect[i].size();j++){
            Vect[i][j]+=Vect[i-1][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << Vect[i][j] << "  ";
        }
        cout << endl;
    }
}