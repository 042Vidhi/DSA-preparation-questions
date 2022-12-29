// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
     	int maxprofit=0;
        int min=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(min>prices[i])
            {
                min=prices[i];
            }
            else if(min<prices[i])
            {
                maxprofit=max(maxprofit,prices[i]-min);
            }
        }
        return maxprofit;
}

int main() {
    int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	cout<<maxProfit(v);
    return 0;
}