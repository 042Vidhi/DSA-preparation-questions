// 316. Remove Duplicate Letters
// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
// the smallest in lexicographical order
//  among all possible results.

//  Example 1:
// Input: s = "bcabc"
// Output: "abc"

// Example 2:
// Input: s = "cbacdcbc"
// Output: "acdb"

// https://leetcode.com/problems/remove-duplicate-letters/description/

//Approach:Create Frequency array and present array
// 1. If the character is already present in the stack, then skip it.--->continue
// 2. If the character is not present in the stack, then check if the top of the stack is greater than the current character and the frequency of the top of the stack is greater than 1, then pop the top of the stack.
// 3. Push the current character in the stack and mark it as present in the present array.
// 4. After the iteration is over, pop all the elements from the stack and reverse the string and return it.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>present(26,0);
        vector<int>freq(26,0);
        stack<int> st;

        for(char ch:s)	freq[ch-'a']++;

        for(auto c:s)
        {
            freq[c-'a']--;
            if(present[c - 'a'])
             continue;
            while(!st.empty() && st.top() > c && freq[st.top() - 'a'] >=1)
            {
                present[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(c);
            present[c-'a']=1;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;


    }
};