// Radix Sort
// It's also a stable sorting algorithm

#include<iostream>
#include<vector>

using namespace std;

void count_sort(int pos,vector<int> &v){
    int n=v.size();
    
    // Frequency Array
    vector<int> freq(10,0);
    for(int i=0;i<n;i++){
        freq[(v[i]/pos)%10]++;
    }

    // Cumulative Frequency
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }

    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[(v[i]/pos)%10]]=v[i];
    }

    // Inserting elements into original array
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }

    return;
}

void radix_sort(vector<int> &v){
    int n=v.size();

    int max=INT8_MIN;
    for(int i=0;i<n;i++){
        if(max<v[i]){
            max=v[i];
        }
    }

    for(int pos=1;(max/pos)>0;pos*=10){
        count_sort(pos,v);
    }

    return;
}

int main(){
    int n;
    cout << "Enter the no. of elements: ";
    cin>> n;

    vector<int> v(n);
    cout << "enter the elements: ";
    for(int i=0;i<n;i++){
        cin>> v[i];
    }

    radix_sort(v);

    for(int i=0;i<n;i++){
        cout << v[i] << "  ";
    }

    return 0;
}