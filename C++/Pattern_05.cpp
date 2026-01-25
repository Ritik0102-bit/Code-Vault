// Pattern
// 1 2 3 4 5 6 
// 1         6
// 1         6
// 1         6
// 1         6
// 1 2 3 4 5 6

#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1 || i==n){
            for(int j=1;j<=n;j++){
            cout<< j << " ";
        }
        }
        else{
            cout<< 1<< " ";
            for(int j=1;j<=n-2;j++){
            cout <<  "  ";
            }
            cout << n << " ";

        }
        cout<<endl;
    }
}
