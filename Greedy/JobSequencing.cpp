// Question)// Given a set of N jobs where each jobi has a deadline and profit associated with it.

// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
#include<bits/stdc++.h>
using namespace std;
struct Job{
    int id;
    int dead;
    int profit;
};
class Solution 
{
    public:
    static bool cmp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<bool> slots(n+1,false);
        int count=0;
        int ans=0;
        sort(arr, arr + n, cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,arr[i].dead);j>0;j--)
            {
                if(!slots[j])
                {
                    slots[j]=true;
                    count++;
                    ans+=arr[i].profit;
                    break;
                }
            }
        }
        return {count,ans};
    } 
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Job arr[n];
        for(int i=0;i<n;i++)
        { int x,y,z;
        cin>>x>>y>>z;
        arr[i].id=x;
        arr[i].dead=y;
        arr[i].profit=z;

        }
        Solution ob;
        vector<int> ans=ob.JobScheduling(arr,n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
}

    return 0;
}