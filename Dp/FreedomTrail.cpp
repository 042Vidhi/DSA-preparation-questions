#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int method(int i1,int i2, string ring, string key,int m,int n, vector<vector<int>>&dp)
    {
        if(i2==n)
          return 0;
        if(dp[i1][i2]!=-1)
          return dp[i1][i2];
        int ans = INT_MAX;
        for(int i=0;i<m;i++)
        {
            if(ring[i]==key[i2])
            {
                int count = min(abs(i1-i),m-abs(i1-i));
                ans = min(ans, count + method(i, i2+1, ring, key, m, n,dp));
            }
        }
        cout<< "dp of "<<i1<<","<<i2<<dp[i1][i2]<<endl;
        return dp[i1][i2]=ans;
    }
    int findRotateSteps(string ring, string key)
    {
        int i1=0,i2=0;
        int n = key.size();
        int m = ring.size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        int ans = method(i1,i2,ring, key,m,n,dp)+n;
        cout<<"dp:\n"<<endl;
        for(int i = 0 ;i<m;i++)
        {
            for(int j = 0 ;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Dp ends"<<endl;
        return ans;
    }
};
int main()
{   
    Solution obj;
    cout<<obj.findRotateSteps("vidhijaiswal","vjswl");



    return 0;
}