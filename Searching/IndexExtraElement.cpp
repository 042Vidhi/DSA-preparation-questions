/*
Given two sorted arrays of distinct elements. There is only 1 difference between the arrays. First array has one element extra added in between. Find the index of the extra element.
Input
7
2 4 6 8 9 10 12
2 4 6 8 10 12
Output
4
*/
#include <iostream>
using namespace std;
int Index(int a[],int b[],int n)
{
	int l=0,h=n-1;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(a[mid]==b[mid])
			l=mid+1;
		else{
			if(a[mid-1]==b[mid-1])
				return mid;
			else if(mid==0)
				return mid;
			else
				h=mid-1;
		}
	}
	return -1;
}
int main() {
    int n;
	cin>>n;
	int a[n],b[n-1];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++)cin>>b[i];
	int extraidx = Index(a,b,n);
	cout<<extraidx<<endl;
    return 0;
}