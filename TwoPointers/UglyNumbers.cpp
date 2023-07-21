/*
264. Ugly Number II
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.
Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.


https://leetcode.com/problems/ugly-number-ii/description/

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        
        int a[n];
        a[0]=1;
        int p1=0,p2=0,p3=0;
        for(int i=1;i<n;i++)
        {
            int val = min(a[p1]*2 , min(a[p2]*3,a[p3]*5));
            a[i] = val;
            if(val == a[p1]*2)p1++;
            if(val == a[p2]*3)p2++;
            if(val == a[p3]*5)p3++;

        }

        return a[n-1];
    }
};