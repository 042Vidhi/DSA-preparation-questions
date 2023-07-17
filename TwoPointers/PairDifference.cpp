/*
Pair with a Difference
Given an array of n integers, and a number k,
find the number of pairs of elements in the array whose difference is k.

Input
6 78
5 20 3 2 5 80
Output
Yes
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long ans = 0;
    int i = 0, j = 1;
    while (i < n && j < n) {
        int diff = a[j] - a[i];
        if (diff == k && i != j) {
            ans = 1;
            break;
        } else if (diff < k) {
            j++;
        } else {
            i++;
        }
    }
    if (ans)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
