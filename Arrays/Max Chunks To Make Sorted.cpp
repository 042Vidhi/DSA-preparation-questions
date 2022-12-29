// https://leetcode.com/problems/max-chunks-to-make-sorted/
#include <bits/stdc++.h>
using namespace std;
int maxChunksToSorted(vector<int> &a)
{	int ans=0;
 	int maxn=0;
 	for (int i = 0; i < a.size(); i++) {
            maxn = max(a[i], maxn);
            if (maxn == i) 
				ans++;
        }
	return ans;
}
int main() {
    int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<maxChunksToSorted(a);
    return 0;
}