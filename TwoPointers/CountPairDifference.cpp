/*
2006. Count Number of Pairs With Absolute Difference K

Given an integer array nums and an integer k, 
return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.

Example 1:
Input: nums = [1,2,2,1], k = 1
Output: 4

Example 2:
Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.

Example 3:
Input: nums = [3,2,1,5,4], k = 2
Output: 3


https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/

*/

//two pointer approach
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int i=0,j=1,ans=0,n=nums.size();
        sort(nums.begin(),nums.end());

        while(i<n && j<n)
        {
            int cur = nums[j]-nums[i];
            if(cur<k)j++;
            else if(cur>k){
                i++;
            }
            else{
                int c1=1,c2=1,v1=nums[i],v2=nums[j];
                while(i+1 < n && nums[i]==nums[i+1])
                {c1++;i++;}
                while(j+1 < n && nums[j]==nums[j+1])
                {c2++;j++;}
                ans+=c1*c2;
                i++;j++;
                
            }
        }
        return ans;
    }
};

