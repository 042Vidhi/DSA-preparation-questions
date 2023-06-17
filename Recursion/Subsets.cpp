// 78. Subsets
// Given an integer array nums of unique elements, return all possible 
// subsets (the power set).

// The solution set must not contain duplicate subsets.
// Return the solution in any order.

// https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//Using Recursion
    vector<vector<int>> ans;
    void PASS(vector<int> &nums,int i,vector<int> temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        
        PASS(nums,i+1,temp);
        temp.push_back(nums[i]);
        PASS(nums,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        PASS(nums,0,temp);
        return ans;
        
    }
};


class Solution {
public:
//Using Bitmasking
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
      int p=pow(2,nums.size());
      for(int i=0;i<p;i++)
      {     
          vector<int> temp;
          for(int j=0;j<nums.size();j++)
          {
              if(i & (1<<j))
              {
                  temp.push_back(nums[j]);
              }
          }
          ans.push_back(temp);
      }
      return ans;
        
    }
};