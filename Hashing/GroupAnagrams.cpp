// 49. Group Anagrams
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]


// https://leetcode.com/problems/group-anagrams/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(auto s:strs)
        {
            string temp =s;
            sort(s.begin(),s.end());
            m[s].push_back(temp);
        }

        for(auto mp : m)
        {
            ans.push_back(mp.second);
        }
        return ans;
    }
};