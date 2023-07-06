/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
You must write an algorithm with O(nlog n) runtime complexity.
*/

#include <iostream>
using namespace std;
int binarySearch(int a[],int n,int key)
{
	int l=0,h=n-1;
	while(l<h)
	{
		int m =(l+h)/2;
		if(a[m]<key)
		{
			 l = m + 1;
		}
		else if(a[m]>key)
		{
			 h = m - 1;
		}
		else if(a[m]==key)
		{
			return m;
		}
	}
	return -1;
}
int main() {
    int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int target;
	cin>>target;
	int index1,index2;
	for(int i=0;i<n;i++)
	{
		int k = target - a[i];
		 index1 = i; 
		 index2 = binarySearch(a,n,k);
        if (index2 != -1 && index1 != index2) {
	        if(index1<index2)
                cout << index1 + 1 << " " << index2 + 1 << endl;
	        else
		        cout << index2 + 1 << " " << index1 + 1 << endl;
            break;
        }
		
	}
	
    return 0;
}