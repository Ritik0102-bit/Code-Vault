

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         long long int n1=0,n2=0;
//         int i=0,j=0;
//         while(l1.next!=NULL){
//             n1+=(l1.val)*(pow(10,i));
//             i++;
//             l1=l1.next;
//         }
//         while(l2.next!=NULL){
//             n2+=(l2.val)*(pow(10,j));
//             j++;
//             l2=l2.next;
//         }

//         long long int n3=n1+n2;
//         ListNode* res=new ListNode();

//         ListNode* temp=res;
//         while(n3>0){
//             int temp=n3%10;
//         }
//     }
// };

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1[nums1.size()-1]==0){
            nums1.pop_back();
        }
        vector<int> res;
        int i=0,j=0,k=0;
        while(i<m+n){
            if(nums1[j]>nums2[k]){
                res.push_back(nums2[k++]);
            }
            else{
                res.push_back(nums1[j++]);
            }
            i++;
        }

        while(j<m){
            if(nums1[j]!=0){
                res.push_back(nums1[j++]);
            }
        }
        while(k<m){
            res.push_back(nums2[k++]);
        }

        nums1 = res;
    }

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    merge(nums1, m, nums2, n);
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    return 0;
}