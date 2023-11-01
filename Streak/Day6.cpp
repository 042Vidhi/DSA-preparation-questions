/*
1356. Sort Integers by The Number of 1 Bits

https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int countSetBits(int n)
    {
        int c=0;
        while(n)
        {
            n=n&(n-1);
            c++;
        }
        return c;
    }
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        //key value vector to store array element and their number of set bits
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++)
        {
            pair<int,int> temp = make_pair(arr[i],countSetBits(arr[i]));
            // v[arr[i]]=countSetBits(arr[i]);
            v.push_back(temp);

        }
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};