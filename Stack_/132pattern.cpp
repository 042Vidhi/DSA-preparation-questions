// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: false
// Explanation: There is no 132 pattern in the sequence.

// Example 2:
// Input: nums = [3,1,4,2]
// Output: true
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

// Example 3:
// Input: nums = [-1,3,2,0]
// Output: true
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

// https://leetcode.com/problems/132-pattern/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int minarr[n];
        minarr[0]=nums[0];
        //prefix min array
        for(int i=1;i<n;i++)
        {
            minarr[i] = min(minarr[i-1],nums[i]);
        }
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>minarr[i])
            {
                while(!st.empty() && st.top() <= minarr[i])
                    st.pop();
                if(!st.empty() && st.top() < nums[i])
                    return true;
                st.push(nums[i]);
            }
        }
        return false;

        
    }
};