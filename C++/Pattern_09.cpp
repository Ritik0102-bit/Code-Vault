// Pattern
//         A 
//       A B C
//     A B C D E
//   A B C D E F G
// A B C D E F G H I
//   A B C D E F G
//     A B C D E
//       A B C
//         A

#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout << "  ";
        }
        char ch='A';
        for(int j=1;j<=((2*i)-1);j++){
            cout << ch << " ";
            ch++;
        }
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n-i;j++){
            cout << "  ";
        }
        char ch='A';
        for(int j=1;j<=((2*i)-1);j++){
            cout << ch << " ";
            ch++;
        }
        cout<<endl;
    }
}
