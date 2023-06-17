// 50. Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

// https://leetcode.com/problems/powx-n/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n<0) {
            n=abs(n);
            x=1/x;
        }
        double t = myPow(x,n/2);
        return n%2==0 ? t*t : t*t*x;
        
    }
};