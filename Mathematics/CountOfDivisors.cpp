// Count of Divisors for multiple queries
// You are given an array A of N integers.
// Count the number of unique prime factors of each element in it.

// Input Format
// The first line of the input contains a single integer T, denoting the number of test cases.
// The description of T test cases follows.
// The first line of each test case contains a single integer N.
// The second line of each test case contains N space-separated array integers

// Output Format
// For each test case output a line containing N space separated integers denoting the number of prime factors of each of the array element.

// Example
// Input
// 1
// 3
// 10 12 14
// Output
// 2 2 2

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
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
		{	int count=0;
			while(spf[arr[i]]!=-1)
			{
				int temp=spf[arr[i]];
				while(arr[i]%temp==0)
				{	
					arr[i] = arr[i]/temp;
				}
				count++;
			}
			 if(arr[i]!=1)
			{
				count++;
			}
			cout<<count<<" ";
		}
		cout<<endl;
	}
    return 0;
}