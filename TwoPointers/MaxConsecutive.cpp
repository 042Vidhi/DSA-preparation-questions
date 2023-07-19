/*
1004. Max Consecutive Ones III
Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

https://leetcode.com/problems/max-consecutive-ones-iii/description/

*/
//two pointer approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,c0=0,n=nums.size(),ans=0;
        while(j<n)
        {
            if(nums[j]==0)c0++;
            while(c0>k)
            {
                if(nums[i]==0)c0--;
                i++;
            }
            j++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};  