//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool memo(int i,int target,vector<int>& nums, vector<vector<int>>& dp)
    {
        if(target==0)return true;
        if(i==0)return nums[0]==target;

        if(dp[i][target]!=-1)return dp[i][target];

        bool nottake = memo(i-1,target,nums,dp);
        bool take = false;
        if(target>=nums[i])
             take = memo(i-1,target-nums[i],nums,dp);

        return dp[i][target] = take||nottake;

    }
    bool isSubsetSum(vector<int>nums, int target){
        // code here 
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        bool ans = memo(n-1,target,nums,dp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout <<"subset sum equals target exists?"<< ob.isSubsetSum(arr, sum) << endl;

    }
    return 0; 
} 

// } Driver Code Ends