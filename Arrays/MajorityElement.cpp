// 169. Majority Element
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times.
//  You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// https://leetcode.com/problems/majority-element/
//Moore's Voting Algorithm - o(n) time and o(1) space 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,ele;
        for(int i=0;i<nums.size();i++)
        {
            if(c==0){
                ele=nums[i];
                c++;
            }
            else if(nums[i]==ele)
            {
                c++;
            }
            else{
                c--;
            }
        }
        int c1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele)c1++;
           
        }
          if(c1>(nums.size()/2)){
                return ele;
            }
        return -1;
    }
};