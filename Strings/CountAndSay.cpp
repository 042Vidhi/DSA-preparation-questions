#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string runlength(string st)
    {
        string ans="";
        int n = st.size();
        int i=0,j=0;
        int cnt =0;
        while(j<n)
        {
            if(st[i]==st[j])
            {
                cnt++;
                j++;
            }
            else{
                ans+=to_string(cnt)+st[i];
                i=j;
                cnt=0;
            }
        }
        ans += to_string(cnt) + st[i];
        return ans;
    }
    string recursion(int i,int n,string s)
    {
        if(i==n)return s;
        string news = runlength(s);
        return recursion(i+1,n,news);
    }
    string countAndSay(int n) {
        string ans = recursion(1,n,"1");
        return ans;
    }
};