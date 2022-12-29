// https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h>
using namespace std;
long long trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftmax(n), rightmax(n);
    for(int i=1;i<n;i++)
    {
        leftmax[i]=max(height[i-1],leftmax[i-1]);
    }
    for(int i = n-2; i >= 0; --i)
    {
        rightmax[i]=max(height[i+1],rightmax[i+1]);
    }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int waterlevel=min(leftmax[i],rightmax[i]);
                if(waterlevel>=height[i])
                    ans+=(waterlevel-height[i]);
        }
        return ans;
    }
int main() {
    int n;
	cin>>n;
	vector <int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	cout<<trap(v);
    return 0;
}