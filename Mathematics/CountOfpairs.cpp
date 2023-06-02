
// Divisible Pairs
// You are given an array A of N numbers, output the count of pairs in the array whose sum is divisible by 4.

// Input Format
// The first line of the input contains a single integer T denoting the number of test cases.
// The description of T test cases follows.
// The first line of each test case contains a single integer N.
// The second line contains N space-separated integers array numbers.

// Output Format
// For each test case, output the count of pairs in the array whose sum is divisible by 4 on a separate line.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int k=4;
		ll count[k]={0};
		for(int i=0;i<n;i++)
		{
			count[arr[i]%k]++;
		}
		ll ans=0;
		ans = ans + (count[0]*(count[0]-1))/2;
		for(int i=1;i<(k/2);i++)
		{
			ans+=count[i]*count[k-i];
		}
		if(k%2==0)
		{
			ans+=(count[k/2]*(count[k/2]-1))/2;
		}
		else{
			ans+=count[k/2]*count[(k/2)+1];
		}
		cout<<ans<<endl;
	}
    return 0;
}