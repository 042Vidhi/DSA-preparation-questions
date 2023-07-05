/*
Given an array of integers nums sorted in ascending order,
 find the starting and ending position of a given target value.

If target is not found in the array, return −1.
You must write an algorithm with O(log(n)) runtime complexity.
Input Format

The first line contains an integer N, number of elements in the array 
The second line contains N space-separated integers 
The third line of the input contains a single integer T denoting
the number of test cases. The description of T test cases follows.
Each test case consists of a positive integer target
Input
5
1 3 3 4 5
2
3
2
Output
2 3
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

int lastOccurrence(int a[], int n, int k) {
    int l = 0, h = n - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (a[m] < k)
            l = m + 1;
        else if (a[m] > k)
            h = m - 1;
        else {
            if(m==n-1)return m;
			else if(a[m+1]!=k)return m;
			else l=m+1;
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
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int first = firstOccurrence(a, n, k);
        int last = lastOccurrence(a, n, k);
        if (first != -1)
            cout << first+1 <<" ";
        if (last == -1)
            cout << last << endl;
        else
            cout << last+1 << endl;
    }
    return 0;
}
