#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumByD(vector<int>& nums, int threshold)
    {
        int sum = 0;
        for(int i =0;i<nums.size();i++)
        {
            sum += ceil((double)(nums[i]) / (double)threshold);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold) return -1;
        int low = 1, high = *max_element(nums.begin(),nums.end());

        while(low<=high)
        {
            int mid = (low+high)/2;
            if(sumByD(nums,mid)<= threshold)
            {
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
};