/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        set <int> st;
        unordered_map<int,int> freq;
        
        //store the elements in set to find distinct number of elements
        for(int x=0;x<n;x++)st.insert(arr[x]);
        
        int i=0,j=0,ans=0,k=st.size();
        
        //two pointer approach
        
        while(j<n)
        {
            freq[arr[j]]++;
            while(freq.size()==k)
            {
                ans += n - j;
                freq[arr[i]]--;
                if(freq[arr[i]]==0) freq.erase(arr[i]);
                
                i++;
            }
            j++;
        }
        
        return ans;
    }
};