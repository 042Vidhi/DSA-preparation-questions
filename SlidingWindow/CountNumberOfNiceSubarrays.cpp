#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCount = 0, niceCount = 0,ans=0;
        int i=0,j=0,n=nums.size();

        while(j<n)
        {
            if (nums[j] % 2 != 0)
            {
                oddCount ++;
                niceCount = 0;
            }
            //moving i++ to cover all subarrays till j where oddCont is k.
            while(oddCount == k)
            {
               
                oddCount -=(nums[i]%2==1);
                i++;
                niceCount++;
            }
            ans += niceCount;
            j++;

        }
        return ans;
    }
};
