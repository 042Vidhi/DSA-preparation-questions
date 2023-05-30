// Given a number N, print all its unique prime factors and their exponents in N.

// Input Format
// The first line of the input contains a single integer T denoting the number of test cases.
// The description of T test cases follows.
// Each test case contains a single integer N in a separate line.

// Output Format
// For each test case, for each prime factor of the number N in that test case, output two space separated integers:
//  the prime factor and its power in N.
// Prime factors should be printed in increasing order.

// Constraints
// 1 ≤ T ≤ 10^5
// 2 ≤ N ≤ 10^6

// Example
// Input
// 2
// 100
// 35
// Output
// 2 2
// 5 2
// 5 1
// 7 1

#include <iostream>
using namespace std;
#define NUM 1000001
int spf[NUM];
int primes[NUM];
void precomputation()
{   
 
    for (int i = 0; i < NUM; i++)
	{
		primes[i]=1;
		spf[i]=-1;
	}
 	primes[1]=0;
    for (int i = 2; i * i <=NUM; i++) {
        if (primes[i] == 1) {
            for (int j = i;i*j <=NUM; j++)
                if (primes[i*j] == 1)
				{
					spf[i*j]=i;
					primes[i*j]=0;
				}
        }
    }
}
int main() {
precomputation();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		while(spf[n]!=-1)
		{
			int count=0,temp=spf[n];
			while(n%temp==0 && n!=1)
			{	count++;
				n = n/temp;
			}
			cout<<temp<<" "<<count<<endl;
		}
		if(n!=1)
		{
			cout<<n<<" "<<1<<endl;
		}
	}  
return 0;
}

