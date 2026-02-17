#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> v;
    v={0,1,2,3,4,5};

    v.push_back(6); // it is used to insert element at the last

    v.begin(); // it gives position of first element
    
    v.end(); // it gives position of last element
    
    v.insert(v.begin()+2,5); // it is used to add element with the help of position
    
    v.pop_back(); // it is used to delete a element from the last

    v.erase(v.begin()); // it is used to delete a element with its position
    // this position is relative position to the fisrt element
    
    reverse(v.begin(),v.end()); // it is used to reverse a vector & it is present in algorithm library
}