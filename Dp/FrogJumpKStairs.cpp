//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int memo(vector<int>& height, int n, vector<int>& dp,int k) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int minsteps = INT_MAX;
        for(int j = 1;j<=k;j++)
        {
            int step = INT_MAX;
            if (n >=j) {
            step = memo(height, n - j, dp,k) + abs(height[n] - height[n - j]);
            }
            minsteps = min(minsteps,step);
        }
        return dp[n] = minsteps;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n + 1, -1);
        return memo(height, n - 1, dp,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends