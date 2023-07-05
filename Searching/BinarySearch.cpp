#include <iostream>
using namespace std;
int binarySearch(int a[],int n,int k)
{
	int l=0,h=n-1;
	while(l<=h)
	{	
		int m=(l+h)/2;
		if(a[m]<k)l=m+1;
		else if(a[m]>k)h=m-1;
		else{
			if(a[m]==k)return m;
			
		}
	}
	return -1;
}
	
int main() {
    int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int t;
	cin>>t;
	while(t--)
	{	int k;
	 	cin>>k;
	 	int result =binarySearch(a,n,k);
		cout<<result<<endl;
	}
    return 0;
}