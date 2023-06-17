// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons). Note that 1 does not map to any letters.
// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]


// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<vector<char>> digitmap{ { 'a','b','c' }, 
                                    { 'd','e','f'}, 
                                    { 'g' , 'h' ,'i'},
                                    {'j','k','l'},
                                    {'m','n','o'},
                                    {'p','q','r','s'},
                                    {'t','u','v'},
                                    {'w','x','y','z'}};
    void combinations(string &temp,int i,string& digits)
    {
        if(digits[i] == NULL)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<digitmap[digits[i]-'2'].size();j++)
        {
            temp.push_back(digitmap[digits[i]-'2'][j]);
            combinations(temp,i+1,digits);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")return ans;
        string temp;
        combinations(temp,0,digits);
        return ans;
    }
};