// Time Complexity :- O(n)
// Space Complexity :- O(1)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If lengths differ, they cannot be isomorphic
        if (s.length() != t.length()) {
            return false;
        }

        // Create two arrays to store the last seen position of each character.
        // We initialize with 0. Size 256 covers all ASCII characters.
        int map_s[256] = {0};
        int map_t[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            // Get ASCII values of the current characters
            char char_s = s[i];
            char char_t = t[i];

            // If the last seen positions of these characters don't match,
            // the mapping is inconsistent.
            if (map_s[char_s] != map_t[char_t]) {
                return false;
            }

            // Update the last seen position. 
            // We use i + 1 because 0 is the default initialization value.
            map_s[char_s] = i + 1;
            map_t[char_t] = i + 1;
        }

        return true;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "egg";
    string t1 = "add";
    cout << "Test 1 (" << s1 << ", " << t1 << "): " 
         << (sol.isIsomorphic(s1, t1) ? "True" : "False") << endl;

    // Test Case 2
    string s2 = "foo";
    string t2 = "bar";
    cout << "Test 2 (" << s2 << ", " << t2 << "): " 
         << (sol.isIsomorphic(s2, t2) ? "True" : "False") << endl;

    // Test Case 3
    string s3 = "paper";
    string t3 = "title";
    cout << "Test 3 (" << s3 << ", " << t3 << "): " 
         << (sol.isIsomorphic(s3, t3) ? "True" : "False") << endl;

    return 0;
}