/*
Find subarray with given sum 

Given an unsorted array A of size N of non-negative integers, 
find a continuous sub-array which adds to a given number S.
return the starting and ending indices(1 indexing) of the first such 
occuring subarray from the left if sum equals to subarray, else return -1.
*/
#include <iostream>
using namespace std;
int main() {
    int t;
	cin>>t;
	while(t--)
	{
		long long n,sum;
		cin>>n>>sum;
		long long a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		
		long long i=0,j=0;
		long long cur = a[0];
		int flag=0;
		while(j<n)
		{
			
			if(cur<sum){j++;
			if(j<n)cur+=a[j];}
			else if(cur>sum){
				cur-=a[i];i++;
				if(i>j){
					j++;
					if(j<n)cur = a[j];
				}
			}
			else if(cur==sum){
				cout<<i+1<<" "<<j+1<<endl;
				flag=1;
				break;
			}
		}
		if(!flag)cout<<"-1"<<endl;
		
		
	}
    return 0;
}