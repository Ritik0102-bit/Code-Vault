// WAP to find whether a number is present in the array or not
// we have to find so many number in the array
// so we will make a frequency array

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    // we will take size of array as 10 power 5
    const int N=1e5; //it is scientific notation of 10 power 5
    // we are initializing freq array to 0 for each index
    vector<int> freq(N,0); 

    // for each value in vector v we will increase its frequency at its index
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }

    // now we will take input elements to search
    int q;
    cout << "Enter quries : ";
    cin >> q;
    int n1;
    for(int i=0;i<q;i++){
        cin >> n1;
        cout << n1 << " : " << freq[n1] <<endl;
    }
    return 0;
}