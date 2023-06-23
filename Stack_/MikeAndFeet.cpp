// Mike and Feet

// -----------------------------------------------
// Mike is the president of country What-The-Fatherland. There are n bears living in this country besides Mike. All of them are standing in a line and they are numbered from 1 to n from left to right. i-th bear is exactly ai feet high.


// A group of bears is a non-empty contiguous segment of the line. The size of a group is the number of bears in that group. The strength of a group is the minimum height of the bear in that group.

// Mike is a curious to know for each x such that 1 ≤ x ≤ n the maximum strength among all groups of size x.
// -----------------------------------------------
// Input
// The first line of input contains integer n (1 ≤ n ≤ 2 × 105), the number of bears.

// The second line contains n integers separated by space, a1, a2, ..., an (1 ≤ ai ≤ 109), heights of bears.

// Output
// Print n integers in one line. For each x from 1 to n, print the maximum strength among all groups of size x.
// -----------------------------------------------
// Examples
// input
// 10
// 1 2 3 4 5 4 3 2 1 6
// output
// 6 4 4 3 3 2 2 1 1 1 
// -----------------------------------------------
// https://codeforces.com/contest/548/problem/D
// -----------------------------------------------

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
 void MikeAndFeet(int heights[],int n)
 {
     vector<int> NGE(n,n),PGE(n,-1),ans(n);
     stack<int> st;
     for(int i=0;i<n;i++)
     {
         while(!st.empty() && heights[i] < heights[st.top()])
         {
             NGE[st.top()] = i;
             st.pop();
         }
         st.push(i);
     }
    for(int i=n-1;i>=0;i--)
     {
         while(!st.empty() && heights[i] < heights[st.top()])
         {
             PGE[st.top()] = i;
             st.pop();
         }
         st.push(i);
     }
     
    for(int i=0;i<n;i++){
        int x = NGE[i]-PGE[i]-2;
        ans[x]=max(ans[x],heights[i]);
    }
    for(int i=n-2;i>=0;i--){
        ans[i] = max(ans[i],ans[i+1]);
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
 }
};
int main()
{
 
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    Solution s;
    s.MikeAndFeet(a,n);

    return 0;
}