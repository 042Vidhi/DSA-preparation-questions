// https://leetcode.com/problems/rotate-array/
#include <bits/stdc++.h>
using namespace std;
 void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
	 for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    }
int main() {
    int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	rotate(a,k);
    return 0;
}