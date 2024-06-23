// https://leetcode.com/problems/sliding-window-maximum/
//using deque to store the max elemet for each subarray
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>maxeles ; 
        int i = 0,j=0,n=nums.size();
        deque<int> max_dec;
        while(j<n)
        {
            while(!max_dec.empty() && nums[j]>max_dec.back()) max_dec.pop_back();
            max_dec.push_back(nums[j]);

            if(j-i+1 == k)
            {
                //reached window size
                maxeles.push_back(max_dec.front());

                if(max_dec.front() == nums[i]) max_dec.pop_front();

                i++;
                j++;

            }
            else if(j-i+1<k)
            {
                j++;
            }
        }

        return maxeles;
    }
};