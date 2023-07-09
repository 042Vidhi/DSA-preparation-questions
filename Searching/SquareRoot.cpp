
/*
Square Root (Integral)
Given a non-negative integer N, compute and print the square root of N. 
Print only the integer part. You must write an algorithm with O(log n) runtime complexity.
Input Format
The first line of input contains T, number of testcases.
Each testcase contains a positive integer N
Constraints
1 ≤ T ≤ 10^5
0 ≤ N ≤ 2^31−1
Output Format
For each testcase, print the square root of the number N.


Example
Input
6 
4
8
16
0
9
2
Output
2
2
4
0
3
1
*/

#include <iostream>
using namespace std;
long long sqrtbinary(int n)
{
	long long l=0,h=n;
	while(l<=h)
	{	
		long long m=(l+h)/2;
		if(m*m>n)
			h=m-1;
		else{
			if((m+1)*(m+1)>n)return m;
			else
				l=m+1;
		}
	}
	
}
int main() {
    int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		cout<<sqrtbinary(x)<<endl;
	}
    return 0;
}