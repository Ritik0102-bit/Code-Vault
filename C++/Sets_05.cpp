// Find the second smallest element from a set

#include<iostream>
#include<set>

using namespace std;

int main(){
    int n;
    cin>>n;

    set<int> s;

    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        s.insert(c);
    }

    auto itr=s.begin();
    itr++;

    cout << "Second Smallest element : "<< *itr;
}