// leetcode 33
// Search element in rotated sorted array with duplicate elements. Return 1 if the element is found, else return -1.

// Input:
// [0,0,0,1,1,1,2,0,0,0], target = 2

// Output:
// 1

// Approach :- when applying binary search , we know that one part of the array is sorted and another part is unsorted.
// So we can apply binary search on the sorted part of the array and then check if the element is present in the sorted part or not.
// If the element is not present in the sorted part , then we can apply binary search on the unsorted part of the array.

#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid]==target){
                return mid;
            }
            if(nums[start] <= nums[mid]){ // If the left part of the array is sorted
                if(nums[start] <= target && target <= nums[mid]){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else{ // If the right part of the array is sorted
                if(nums[mid] <= target && target <= nums[end]){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
}

int main(){
    vector<int> nums = {0,0,0,1,1,1,2,0,0,0};
    cout<<search(nums,2)<<endl;
    return 0;
}