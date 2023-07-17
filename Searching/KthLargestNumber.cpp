/*
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int x, vector<int>& nums, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > x) count++;
        }
        return count;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int c1 = func(mid, nums, n);
            if (c1 > k)
                low = mid + 1;
            else {
                int c2 = func(mid + 1, nums, n);
                if (c2 >= k) return mid;
                else high = mid - 1;
            }
        }
        return -1;
    }
};
