/*
Sort by Frequency
Given an integer array nums, sort the array according to frequency of elements. 
That is elements that have higher frequency come first.
 If frequencies of two elements are same, then smaller number comes first.

Input Format
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers denoting the elements of the array.
Output Format
For each testcase, in a new line, print each sorted array in a seperate line. 
For each array its numbers should be seperated by space.

Input
2  
5  
5 5 4 6 4  
5  
9 9 9 2 5
Output
4 4 5 5 6  
9 9 9 2 5
*/



#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b)
{
	return a.second<b.second;
}
int main() {
    int t;cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> A(n);
		for(int i=0;i<n;i++)cin>>A[i];
		unordered_map<int,int> umap;
		for(int x:A)umap[x]++;
		sort(begin(A), end(A), [&](int a, int b) {
            return umap[a] == umap[b] ? a < b : umap[a] > umap[b];
        });
		for(auto x:A)cout<<x<<" ";
		cout<<endl;
	}
    return 0;
}