// Majority Element

// Given an integer array of size n, find all elements that appear more than [n/3 ] times.
// nums[ ] = {1, 3, 2, 5, 1, 3, 1, 5, 1};
// 1
// nums[ ] = {1, 2};
// 1, 2


// Majority Element in an Array
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/3 ⌋ times. 

// Arr = [3,2,3]
// Output: 3

// Approach 1: Hashing
// We can use a hash map to count the frequency of each element in the array. Then  we can iterate through the hash map to find the element that appears more than n/3 times.

// Time Complexity: O(n) - We traverse the array once to count the frequencies and then traverse the hash map to find the majority element.
// Space Complexity: O(n) - In the worst case, we may have n/3
// unique elements in the array, which would require O(n) space for the hash map.   

// Approach 2: Boyer-Moore Voting Algorithm
// The Boyer-Moore Voting Algorithm is an efficient algorithm to find the majority element in linear time and constant space. The idea is to maintain a count of the current candidate for the majority element and update it as we traverse the array. 

// Time Complexity: O(n) - We traverse the array once to find the majority element.
// Space Complexity: O(1) - We only use a constant amount of space to store
// the candidate and its count.

// code implementation for Approach 2:

// import java.util.HashMap;    
// public class Hashing_00 {
//     public int majorityElement(int[] nums) {
//         HashMap<Integer, Integer> countMap = new HashMap<>();
//         int n = nums.length;
//         for (int num : nums) {
//             countMap.put(num, countMap.getOrDefault(num, 0) + 1);
//         }

public class Hashing_00 {
    
}
