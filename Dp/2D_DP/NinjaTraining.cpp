//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int day,int last,vector<vector<int>>&dp,vector<vector<int>>& arr)
{
    if(day==0)
    {
        //for last case just find max
        int maxi = 0;
        for(int task = 0;task<3;task++)
        {
            if(task!=last)
            {
                maxi = max(maxi , arr[0][task]);
            }
        }
        return dp[day][last] = maxi;

    }

    if(dp[day][last]!=-1) return dp[day][last];

    int maxi =0;
    for(int task = 0;task<3;task++)
    {
        if(task!=last)
        {
            int points = arr[day][task] + helper(day-1,task,dp,arr);
            maxi = max(maxi , points);
        }
    }
    return dp[day][last] = maxi;

}
int maximumPoints(vector<vector<int>>& arr, int n) {
       vector<vector<int>>dp(n,vector<int>(4,-1));
       int ans =  helper(n-1,3,dp,arr);
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
       return ans;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends