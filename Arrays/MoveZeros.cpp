#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int idx = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            else{
                nums[idx] = nums[i];
                idx++;
            }
        }
        for(int i=1;i<=count;i++)
        {
            nums[idx]=0;
            idx++;
        }
    }
};