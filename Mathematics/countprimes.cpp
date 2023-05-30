// Ques) Given an integer n, return the number of prime numbers that are strictly less than n.
// https://leetcode.com/problems/count-primes/description/


class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        int primes[n+1];
        int count=0;
        for(int i=0;i<=n;i++)
        {
            primes[i]=1;
        }
        primes[0]=0;
        primes[1]=0;
        for(int i=2;i*i<=n;i++)
        {
            if(primes[i]==1)
            {
                for(int j=i;i*j<=n;j++)
                {
                    primes[i*j]=0;
                }
            }
        }
        for(int i=2;i<n;i++)
        {if(primes[i]==1)
            count++;
        }
        return count;
    }
};