//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int largestPowerOf2(int n)
    {
        int p = 0;
        while((1<<p)<=n)
        {
            p++;
        }
        return p-1;
    }
    int countSetBits(int n)
    {
        if(n<=0)return 0;
        int x = largestPowerOf2(n);
        int a1 = x * (1<<(x-1));
        int a2 = (n - (1<<x) + 1);
        int sum = a1 + a2 + countSetBits(n - (1<<x));
        
        return sum;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends