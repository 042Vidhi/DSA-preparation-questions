// You are given an array nums of size n.
//  Your task is to convert all the even numbers in the array to the odd numbers first by decreasing them by 1 and then find the maximum subarray sum of size k having all the elements disk in that aubarray. If no subarray satisfies the condition, return 0 in that cass

// Constraints:

// 1 <=n<= 100000

// 1 <= arr[i] <= '2000

// 1< k < n

// Input Format

// The first line contains two Integers, n and k.

// The second line contains the 'n' elements of the Array

// Output Format

// Print a single number x-the maximum subarray sum satisfying the condition

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    //convert all even numbers to odd numbers
    for(int i=0;i<n;i++)
    {
        if(v[i]%2==0) v[i]--;
    }
    //find the maximum subarray sum of size k
    int prefixsum=0;
    for(int i=0;i<k;i++) prefixsum+=v[i];

    int ans=prefixsum;
    for(int i=k;i<n;i++)
    {
        prefixsum+=v[i]-v[i-k];
        ans=max(ans,prefixsum);
    }
    cout<<ans<<endl;

}