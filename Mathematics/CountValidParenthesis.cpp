
// Ques) Count Valid Paranthesis

// You are given a non-negative number N, find the number of valid parentheses expressions of that length. 
// If the answer exists, print the answer modulo 10^9 + 7, otherwise print -1.

// Input Format
// The first line of the input contains a single integer T denoting the number of test cases.
// Each test case contains a single integer N.
// Output Format
// For each test case, output the number number of valid parentheses expressions of length N, on a seperate line.
// Example
// Input
// 2
// 4
// 5
// Output
// 2
// -1

//Solution
// Using the Catalan Number Formula

#include <iostream>
using namespace std;
int main() {
	long long cnt[1001];
	cnt[0]=1;
	cnt[1]=1;
	long long m = 1e9+7;
	for(int i=2;i<1001;i++)
	{
		cnt[i]=0;
		for(int j=0;j<i;j++)
		{
			cnt[i]=(cnt[i]+(cnt[j]*cnt[i-1-j])%m)%m;
		}
	}
    int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n%2==0)
		cout<<cnt[n/2]%m<<endl;
		else
			cout<<"-1"<<endl;
	}
    return 0;
}