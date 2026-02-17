// WAP to sort even and odd numbers in an array
// 1 2 3 4 5 6 7
// output 6 2 4 3 5 1 7

#include<iostream>
#include<vector>

using namespace std;

void sortByParity(vector<int> &v){
    int left_pointer=0;
    int right_pointer=v.size()-1;

    while(left_pointer<right_pointer){
        if(v[left_pointer]%2!=0 && v[right_pointer]%2==0){
            swap(v[left_pointer++],v[right_pointer--]);
        }
        if(v[left_pointer]%2==0){
            left_pointer++;
        }
        if(v[right_pointer]%2!=0){
            right_pointer--;
        }
    }
}

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> v;
    cout << "Enter elements : ";
    for(int i=0;i<n;i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    
    sortByParity(v);
    
    for(int i=0;i<n;i++){
        cout << v[i];
    }
}