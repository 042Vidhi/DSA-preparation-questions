/*
Index of Insertion
Given a sorted array of distinct integers  and a target value, 
print the index if the target is found. If not, print the index where it would be if it were inserted in order. 
You must write an algorithm with O(log n) runtime complexity.

Input Format

The first line of input contains N, size of the array
The second line of input contains N space-separated array elements 
The third line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
Each test case consists of a positive integer target
Output Format

For each testcase, print the index if the target is found. If not, print the index where it would be if it were inserted in order.
Sample Input 0

4
1 3 5 6
4
5
2
7
0

Sample Output 0

2
1
4
0

Explanation

5 is present at position 
2 will be inserted at position 1
7 will be inserted at position 4
0 will be inserted at position 0

*/





#include <iostream>
using namespace std;

int indexInsertion(int a[], int n, int k) {
    int l = 0, h = n - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (a[m] < k)
            l = m + 1;
        else if (a[m] > k)
            h = m - 1;
        else
            return m; // Found the element, return its index
    }
    return l; // Return the index where the element should be inserted
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
        int result = indexInsertion(a, n, k);
        cout << result << endl;
    }
    return 0;
}
