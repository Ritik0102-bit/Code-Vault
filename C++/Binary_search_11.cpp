// You have 'n' (n<=10^5) boxes of chocolate. Each box contains a[i] (a[i]<=10000) chocolates. You need to distribute these boxes among 'm' students such that the maximum number of chocolates allocated to a student is minimum.

// a. One box will be allocated to exactly one student.
// b. All the boxes should be allocated.
// c. Each student has to be allocated at least one box.
// d. Allotment should be in contiguous order, for instance, a student cannot be allocated box 1 and box 3, skipping box 2.

// Calculate and return that minimum possible number.
// Assume that it is always possible to distribute the chocolates.

// The first line of input will contain the value of n, the number of boxes.
// The second line of input will contain the n numbers denoting the number of chocolates in each box.
// The third line will contain the m, number of students.

// Input
// 4
// 12 34 67 90
// 2

// Output
// 113

#include<iostream>
#include<vector>

using namespace std;

bool is_it_minimum(vector<int> &v,int mid,int no_of_students){
    int n=v.size();
    int students_required=1;
    int current_sum=0;

    for(int i=0;i<n;i++){
        if(v[i]>mid){
            return false;
        }
        if(current_sum+v[i]>mid){
            students_required++;
            current_sum+=v[i];
            if(students_required>no_of_students){
                return false;
            }
        }
        else{
            current_sum+=v[i];
        }
    }
    return true;
}

int minimum_chocolates(vector<int> &v,int no_of_students){
    int n=v.size();
    
    int low=v[0];
    int high=0;

    for(int i=0;i<n;i++){
        high+=v[i];
    }

    int ans=-1;

    while(low<=high){
        int mid=low + (high-low)/2;
        if(is_it_minimum(v,mid,no_of_students)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> v={12,34,67,90};
    
    int no_of_students=2;

    cout << minimum_chocolates(v,no_of_students);

    return 0;
}