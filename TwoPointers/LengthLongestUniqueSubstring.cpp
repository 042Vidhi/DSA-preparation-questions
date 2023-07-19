/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.


https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

#include <bits/stdc++.h>
using namespace std;

//two pointer approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        unordered_map<char, int> freq;
        int i = 0, j = 0, ans = 1;
        freq[s[0]]++;
        while (j < s.size() - 1) {
            if (freq[s[j+1]] == 0) {
                freq[s[j+1]]++;
                j++;
            }
            else {
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j - i+1);
        }
        return ans;
    }
};
