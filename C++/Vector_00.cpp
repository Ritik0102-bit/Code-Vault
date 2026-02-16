#include<iostream>
#include<vector>

using namespace std;

int main(){
    // Creating a vector of 5 elements from
    // initializer list
    vector<int> v1 = {1, 4, 2, 3, 5};

    // Creating a vector of 5 elements with
    // default value
    vector<int> v2(5, 9);
    
    vector<int> v;
    
    cout << "size: " << v.size() << endl; // this function returns the length of the vector
    cout << "capacity: " << v.capacity() << endl; // this function returns the capacity of the vector
    // when we insert the elements one by one , then this capacity is increasing in the powers of 2
    // 1,2,4,8,16
    // when we resize the vector in one time then we don't know the capacity it's compiler dependent
    
    v.push_back(1);  // it is used to insert element at the last
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(2);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(3);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(4);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(5);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.resize(8);  // this function resize the length of the vector

}