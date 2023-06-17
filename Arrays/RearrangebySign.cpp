// 2149. Rearrange Array Elements by Sign
// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should rearrange the elements of nums such that the modified array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


//Two pointer approach when equal number of positive and negative numbers are present
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0,n=1;
        vector<int> r(nums.size(),0);
        for(auto num : nums)
        {
            if(num>0)
            {
                r[p]=num;
                p=p+2;
            }
            else if(num<0){
                r[n]=num;
                n=n+2;
            }
        }
        return r;
    }
};