#include <bits/stdc++.h>
using namespace std;

    void lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n,1);
        vector<int>ind(n);
        vector<int>seq;
        for(int i=0;i<n;i++)
        {
            ind[i] = i;
        }
        int indexlast = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[j]<nums[i] && lis[i]<lis[j]+1)
                {
                    lis[i] = max(lis[i],lis[j]+1);
                    ind[i] = j;
                }
            }
        }

        int maxi = lis[0];
        for(int i=0;i<n;i++)
        {
            if(lis[i]>maxi)
            {
                indexlast=i;
                maxi =lis[i];
            }
        }
        //BACKTRACK
        while(indexlast!=ind[indexlast])
        {
            seq.push_back(nums[indexlast]);
            indexlast=ind[indexlast];

        }
        seq.push_back(nums[indexlast]);
        reverse(seq.begin(),seq.end());
        for(int i:seq)
        {cout<<i<<" ";}
    }
    int main()
    {
        vector<int>nums = {5,4,11,1,16};
        lengthOfLIS(nums);
    }