// 46. Permutations (Leetcode)
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:
// Input: nums = [1]
// Output: [[1]]
//https://leetcode.com/problems/permutations/description/
// #include <bits/stdc++.h>
// using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    void permutation(vector<int>&s,int i,int n)
    {
        if(i==n-1){
            result.push_back(s);
            return;
        }
        for(int j=i;j<n;j++)
        {
            swap(s[i],s[j]);
            permutation(s,i+1,n);
            swap(s[i],s[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        permutation(nums,0,nums.size());
        return result;
    }
};