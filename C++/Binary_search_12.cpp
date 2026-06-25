// A new racing track for kids is being built in New York with 'n' starting spots. The spots are located along a straight line at positions x1, x2, ..., xn (xi <= 10^9). For each 'i', xi+1 > xi.
// At a time only 'm' children are allowed to enter the race. Since the race track is for kids, they may run into each other while running. To prevent this, we want to choose the starting spots such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// The first line of input will contain the value of n, the number of starting spots.
// The second line of input will contain the n numbers denoting the location of each spot.
// The third line will contain the value of m, number of children.

// Input
// 5
// 1 2 4 8 9
// 3

// Output
// 3

#include <iostream>
#include <vector>
using namespace std;

bool can_place_children(vector<int> &pos, int no_of_children, int mid) {
    int studentsReqd = 1;
    int lastPlaced = pos[0];
    for(int i = 1; i < pos.size(); i++) {
        if(pos[i] - lastPlaced >= mid) {
            studentsReqd++;
            lastPlaced = pos[i];
            if(studentsReqd == no_of_children) {
                return true;
            }
        }
    }
    return false;
}

int race(vector<int> &pos, int no_of_children) {
    int n = pos.size();
    int low = 1;
    int high = pos[n-1] - pos[0];
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(can_place_children(pos, no_of_children, mid)) {
            ans = mid;
            low = mid + 1;
        } 
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> pos;
    while(n--) {
        int x;
        cin>>x;
        pos.push_back(x);
    }

    int no_of_children;
    cin >> no_of_children;
    cout << race(pos, no_of_children) << "\n";

    return 0;
}