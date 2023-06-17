// 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

// https://leetcode.com/problems/generate-parentheses/description/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void pp(int n,int l,int r,int i,string &s)
    {
        if(i==2*n)
        {
            // cout<<s<<endl;
            ans.push_back(s);
            return;
        }
        if(l==r)
        {
            s[i]='(';
            pp(n,l+1,r,i+1,s);
        }
        else if(l>r)
        {
            if(l==n)
            {
                s[i]=')';
                pp(n,l,r+1,i+1,s);
            }
            else{
                s[i]='(';
                pp(n,l+1,r,i+1,s);
                s[i]=')';
                pp(n,l,r+1,i+1,s);
            }
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string sub(2 * n, ' ');
        pp(n,0,0,0,sub);
        return ans;
    }
};




// The code is implementing a backtracking algorithm to generate all valid combinations of parentheses. Here's a step-by-step explanation of each line of the code and its corresponding operation in the recursive tree diagram:

// vector<string> ans;

// This line declares a vector of strings to store the generated combinations of parentheses.
// void pp(int n, int l, int r, int i, string& s)

// This line defines a recursive function pp that takes the following parameters:
// n: The total number of pairs of parentheses.
// l: The count of open parentheses "(" encountered so far.
// r: The count of closing parentheses ")" encountered so far.
// i: The current index being processed in the string s.
// s: The string representing the current combination of parentheses.
// if (i == 2 * n) { ... }

// This condition checks if we have reached the end of the string s. If we have, it means we have generated a valid combination of parentheses. In this case, we add the combination to the ans vector and return from the current recursive call.
// if (l == r) { ... }

// This condition checks if the count of open parentheses l is equal to the count of closing parentheses r. If they are equal, it means we can only add an open parenthesis "(" at the current index i to maintain validity. So we set s[i] to "(" and make a recursive call with an incremented l.
// else if (l > r) { ... }

// This condition checks if the count of open parentheses l is greater than the count of closing parentheses r. If it is, we have two choices: we can either add an open parenthesis "(" or a closing parenthesis ")" at the current index i.
// if (l == n) { ... }

// This condition checks if we have already used all the available pairs of open parentheses. If l is equal to n, it means we can only add closing parentheses ")" to maintain validity. So we set s[i] to ")" and make a recursive call with an incremented r.
// else { ... }

// If the above condition is not satisfied, it means we can add either an open parenthesis "(" or a closing parenthesis ")" at the current index i. We try both options:
// First, we set s[i] to "(" and make a recursive call with an incremented l.
// Then, we set s[i] to ")" and make a recursive call with an incremented r.
// vector<string> generateParenthesis(int n) { ... }

// This function takes an integer n as input, representing the total number of pairs of parentheses to generate.
// It initializes an empty string sub.
// It calls the pp function to generate all combinations of parentheses by passing the initial values of n, l, r, i, and sub.
// Finally, it returns the ans vector containing all the generated combinations of parentheses.
// By recursively exploring different choices for open and closing parentheses at each index, the algorithm generates all possible valid combinations of parentheses. The backtracking nature of the algorithm ensures that invalid combinations are pruned, leading to only valid combinations being added to the result vector.