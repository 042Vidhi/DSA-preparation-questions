// Ques)There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where
//  start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting 
// can be held in the meeting room at a particular time?

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector <pair<int,int>> vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i] = {start[i],end[i]};
            //   pair<int , int >p  = make_pair(start[i] , end[i]);
            //   vec.push_back(p);
        }
            sort(vec.begin() ,vec.end(), cmp);
            int ans=1;
            int end_time = vec[0].second;
            for(int i=1;i<n;i++)
            {
                if(vec[i].first > end_time)
                {
                    ans++;
                    end_time = vec[i].second;
                }
            }
        return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int start[n],end[n];
        for(int i=0;i<n;i++)start[i];
        for(int i=0;i<n;i++)end[i];

        Solution obj;
        int ans = obj.maxMeetings(start,end,n);
        cout<< ans<<endl;

    }
    return 0;
}