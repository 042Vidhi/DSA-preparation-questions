//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    long long int mod= 1e9+7;
    long long int topd(int n,vector<long long int>& dp)
    {
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = (topd(n-1,dp)+topd(n-2,dp))%mod;
    }
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int>dp(n+1,-1);
        return topd(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
        if(n<=1)return n;
        
        int a=0,b=1,c;
        for(int i = 2 ; i <= n ;i++)
        {
            c = (b+a)%mod;
            a = b;
            b = c;
        }
        return c%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends