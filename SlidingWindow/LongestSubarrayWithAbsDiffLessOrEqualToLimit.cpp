// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
//using two deque to store the max and min element in the subarray
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_dec;
        deque<int> min_inc;
        int max_len = 0 ;
        int i = 0,j=0;
        int n = nums.size();

        while(j<n)
        {
            //first remove the element from deque [remove smaller,j,smaller works ]
            while(!max_dec.empty() && nums[j]>max_dec.back())
            {
                max_dec.pop_back();
            }
            //add the element to the deque 
            max_dec.push_back(nums[j]);
            //do the same for min deque
            while(!min_inc.empty() && nums[j]<min_inc.back())
            {
                min_inc.pop_back();
            }
            min_inc.push_back(nums[j]);
            //if (maxele- minele) > limit -> i++ //use while loop
            while(max_dec.front() - min_inc.front() > limit)
            {
                //also remove the ith element from the both the deque if present
                if(nums[i]==max_dec.front()) max_dec.pop_front();
                if(nums[i]==min_inc.front()) min_inc.pop_front();

                i++;
            } 

            max_len =max(max_len,j-i+1);
            //otherwise just increse j
            j++;
        }

        return max_len;
    }
};