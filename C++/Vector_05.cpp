// WAP to sort a array of the square of its elements in increasing order
// input -10 -3 2 4 6 7
// output 100 49 36 16 9

#include<iostream>
#include<vector>

using namespace std;

void sortedSquaredArray(vector<int> &v){
    vector<int> ans;

    int left_pointer=0;
    int right_pointer=v.size()-1;

    while(left_pointer<right_pointer){
        if(abs(v[left_pointer])<abs(v[right_pointer])){
            ans.push_back(v[right_pointer]*v[right_pointer]);
            right_pointer--;
        }
        else{
            ans.push_back(v[left_pointer]*v[left_pointer]);
            left_pointer++;
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<< ans[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the size of the vector: ";
    cin>> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    sortedSquaredArray(v);

}