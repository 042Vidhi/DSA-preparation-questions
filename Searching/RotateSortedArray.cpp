/*

*/



#include <iostream>
using namespace std;
int pivotpoint(int arr[],int n)
{
	int l=0,h=n-1;
	while(l<=h)
	{
		int mid=(l+h)/2;
			if(arr[mid]<=arr[n-1])
			{
				h=mid-1;
			}
			else
			{
				if(arr[mid]>arr[mid+1])
				{
					return mid;
				}
				else
					l=mid+1;
			}
	}
	return -1;
}
int binary(int arr[],int n,int target,int pivot)
{
	int l,h;
 
	if(target<=arr[n-1])
	{
		l=pivot+1;h=n-1;
	}
	else{
		l=0;h=pivot;
	}
	while(l<=h)
	{
		int mid= (l+h)/2;
		if(arr[mid]==target)
		{
			return mid;
		}
		else if(arr[mid]>target)
		{
			h=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return -1;
}
int main() {
    int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	int t;
	cin>>t;
	while(t--)
	{
		int target;
		cin>>target;
		int pivot = pivotpoint(arr,n);
		int result = binary(arr,n,target,pivot);
		cout<<result<<endl;
	}
    return 0;
}