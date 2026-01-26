// Sample Input 0
// 3
// Sample Output 0
// *   *   *
//   *   *   *
// *   *   *

// Sample Input 1
// 4
// Sample Output 1
// *   *   *   *   
//   *   *   *   * 
// *   *   *   *   
//   *   *   *   * 

#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        if(i%2!=0){
            cout << " " ;
        }
        for(int j=0;j<n;j++){
            cout << "* " ;
        }
        cout << endl;
    }
}