/*
First 1 in Array
Given a sorted array consisting of . The task is to print the index of first 1
 in the given array. You must write an algorithm with O(log n) runtime complexity.

Input Format

The first line of input contains N, size of the array
The second line of input contains N space-separated array elements
Output Format

Print index of the first 1 or print −1.
Sample Input 0
5
0 0 0 1 1

Sample Output 0

4

Sample Input 1

3
0 0 0

Sample Output 1

-1


*/

#include <iostream>
using namespace std;

int firstOccurrence(int a[], int n, int k) {
    int l = 0, h = n - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (a[m] < k)
            l = m + 1;
        else if (a[m] > k)
            h = m - 1;
        else {
           if(m==0)return m;
			else if(a[m-1]!=k)return m;
			else h=m-1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int first = firstOccurrence(a, n, 1);
	if(first!=-1)
	cout<<first+1<<endl;
	else
	cout<<first<<endl;
    return 0;
}