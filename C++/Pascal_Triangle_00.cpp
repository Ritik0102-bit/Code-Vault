// 1st Method
// we know that every element of pascal triangle can be finded by the sum of previous row element &
// previous row previous column element

#include<iostream>
#include<vector>

using namespace std;

auto Pascal_Triangle(int n){
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        // we are resizing every row vector to size i+1 
        ans[i].resize(i+1);

        for(int j=0;j<i+1;j++){
            if(j==0 || i==j){
                ans[i][j]=1;
            }
            else{
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the no. of rows in Pascal Triangle: ";
    cin >> n;

    vector<vector<int>> ans;
    ans= Pascal_Triangle(n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
}