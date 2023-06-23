// 907. Sum of Subarray Minimums
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 1e9 + 7

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444

// https://leetcode.com/problems/sum-of-subarray-minimums/description/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    int n=arr.size();
     vector<int> NSE(n,n),PSE(n,-1);
     stack<int> st;
     for(int i=0;i<n;i++)
     {
         while(!st.empty() && arr[i] < arr[st.top()])
         {
             NSE[st.top()] = i;
             st.pop();
         }
         st.push(i);
     }
    while(!st.empty()){
             st.pop();
     }
    for(int i=n-1;i>=0;i--)
     {
         while(!st.empty() && arr[i]<=arr[st.top()])
         {
             PSE[st.top()] = i;
             st.pop();
         }
         st.push(i);
     }
     int ans=0;
     long long mod=1e9 + 7;
     for(int i =0 ;i<n;i++)
     {  
             long long int x=(i-PSE[i])*(NSE[i]-i)*1LL;
             x=((x%mod)*(arr[i]%mod))%mod;
             ans=((ans%mod)+(x%mod))%mod;
             ans=(ans%mod);
     }
     return ans;
    }
};