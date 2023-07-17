/*
Pair with a Sum

Given an array of n integers, and a number k, 
determine if there is a pair of elements in the array that sums to exactly k.

Input
6 16
1 4 45 6 10 8
Output
Yes

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the array in ascending order
    sort(a, a + n);

    bool ans = false;
    int i = 0, j = n - 1;

    // Two-pointer approach
    while (i < j) {
        int cur = a[i] + a[j];
        if (cur < k) {
            i++;
        } else if (cur == k) {
            ans = true;
            break;
        } else {
            j--;
        }
    }

    if(ans)cout<<"Yes"<<endl;
	else{cout<<"No"<<endl;}
    return 0;
}
