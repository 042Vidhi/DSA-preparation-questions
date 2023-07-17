/*
Count pairs with given sum
Given an array of integers, and a number ‘sum’, 
find the number of pairs of integers in the array whose sum is equal to ‘sum’.

Input
4 6
1 5 7 1
Output
2

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the array in ascending order
    sort(a, a + n);

    long long ans = 0;
    long long i = 0, j = n - 1;

    // Two-pointer approach
    while (i < j) {
        int cur = a[i] + a[j];
        if (cur < k) {
            i++;
        } else if (cur>k) {
            j--;
        } else {
           if(a[i]==a[j]){
			   long long l = j-i+1;
			   ans+=((l-1)*l)/2;
			   break;
		   }
			long long v1=a[i],v2=a[j],c1=0,c2=0;
			while(a[i]==v1){
				i++;c1++;
			}
			while(a[j]==v2)
			{
				j--;c2++;
			}
			ans+=(c1*c2);
        }
    }

    cout<<ans<<endl;

    return 0;
}
