// Given 2 vectors v1 and v2. Find out the common elements between the two and return the sum of them.

// Input:
// V1 = {1, 1, 2, 3, 3, 3}
// V2 = {5, 6, 7, 5, 2, 3, 6}

// Output: 5

// Explanation: The values common between V1 and V2 are: 2, 3. So, sum is 2+3 = 5.

// Time Complexity:- O(n logn + m logn);

#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    vector<int> V1 = {1, 1, 2, 3, 3, 3};
    vector<int> V2 = {5, 6, 7, 5, 2, 3, 6};

    set<int> s;
    // Insert elements of vector 1 to a set & then we will search for common elements

    for(int i:V1){
        s.insert(i);
    }

    int sum=0;

    for(int i:V2){
        if(s.find(i)!=s.end()){
            sum+=i;
            // Remove the element from the set , so it isn't counted twice
            s.erase(i);
        }
    }

    cout << sum;
}