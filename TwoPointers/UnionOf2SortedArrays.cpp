/*

Given two sorted arrays, find their union 

Input
5 3
1 2 3 4 5
1 2 3
Output
1 2 3 4 5

*/

//using Set -- Brute Force
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
	cin>>n>>m;
	set<int>st;
	int a[n],b[m];
	for(int i=0;i<n;i++){cin>>a[i]; st.insert(a[i]);}
	for(int i=0;i<m;i++){cin>>b[i];st.insert(b[i]);}
	for(auto x:st)cout<<x<<" ";
    return 0;
}
*/

//using Two pointer optimal approach

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++){cin>>a[i]; }
	for(int i=0;i<m;i++){cin>>b[i];}
	int i=0,j=0;
	vector<int> unionarr;
	while(i<n && j<m)
	{
		if(a[i]<=b[j])
		{
			if(unionarr.size()==0 || unionarr.back()!=a[i])
			{
				unionarr.push_back(a[i]);
			}
			i++;
		}
		else{
			if(unionarr.size()==0 || unionarr.back()!=b[j])
			{
				unionarr.push_back(b[j]);
			}
			j++;
		}
	}
	while(j<m)
	{
		if(unionarr.size()==0 || unionarr.back()!=b[j])
			{
				unionarr.push_back(b[j]);
			}
			j++;
	}
	while(i<n)
	{
		if(unionarr.size()==0 || unionarr.back()!=a[i])
			{
				unionarr.push_back(a[i]);
			}
			i++;
	}
	for(auto x:unionarr)cout<<x<<" ";
    return 0;
}
