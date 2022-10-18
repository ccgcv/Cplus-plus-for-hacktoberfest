
// question: Given a string s, find the length of the longest substring without repeating characters.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> v(256, 0);
        int start = 0, lString = 0;
        for (int end = 0; end < s.length(); end++)
        {
            v[s[end]]++;
            while (v[s[end]] > 1)
            {

                v[s[start]]--;
                start++;
            }
            lString = max(lString, end - start + 1);
        }
        return lString;
    }
};

int main()
{
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str);
    return 0;
}

// Approach: Sliding window
// We can use a sliding window to solve this problem. The sliding window is a technique that uses two pointers to keep track of a substring in a string. The two pointers are the start and end of the substring.
// We use the end pointer to expand the substring until we get a repeating character in the substring. At this point, we contract (start pointer) and repeat the same process again until we get a substring without any repeating characters.
//
// The algorithm is as follows:
// 1. Create a set to store the characters in the current window.
// 2. Create some variables lString to store the length of the longest substring without repeating characters, start to store the start of the current window, and end to store the end of the current window.
// 3. Loop through the string s from start to end.
// 4. If the character at the end pointer is not in the set, then add it to the set and increment the end pointer.
// 5. If the character at the end pointer is in the set, then remove the character at the start pointer from the set and increment the start pointer.
// 6. Update the length of the longest substring without repeating characters.
// 7. Return the length of the longest substring without repeating characters.

// Time complexity: O(n)
// Space complexity: O(1)