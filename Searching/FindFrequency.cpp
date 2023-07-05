/*
Find Frequency
Given an array of integers, nums sorted in ascending order, and a target value.
 Print the number of occurrences of the target in the given array.
  You must write an algorithm with O(log(n)) runtime complexity.

Input
5 
1 2 2 4 5
5
1
2
3
4
5
Output
1
2
0
1
1
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
        if (first != -1 && last!=-1)
            cout << last-first+1 <<endl;
        else
            cout << 0 << endl;
    }
    return 0;
}