//using memo instead of recursion
#include <bits/stdc++.h>
using namespace std;
int tribo(int n,vector<int>& dp)
{
    if(n==0)return 0;
    if(n==1 || n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = tribo(n-1,dp)+tribo(n-2,dp)+tribo(n-3,dp);
}
int tribonacci(int n)
{
    vector<int> dp(n+1,-1);
    return tribo(n-1,dp);
}
int main()
{
    int n = 5;
    cout<<tribonacci(n);
    return 0;
}