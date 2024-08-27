#include<bits/stdc++.h>
using namespace std;
//summation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i:nums)sum+=i;
        int n = nums.size();
        int sum2 = (n*(n+1))/2;
        return sum2-sum;
    }
};
//bitwise
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int ans = nums.size();

    for (int i = 0; i < nums.size(); ++i)
      ans ^= i ^ nums[i];

    return ans;
  }
};