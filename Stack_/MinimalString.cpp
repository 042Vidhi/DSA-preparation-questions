// Minimal string

// Petya recieved a gift of a string s with length up to 105 characters for his birthday. He took two more empty strings t and u and decided to play a game. This game has two possible moves:

// Extract the first character of s and append t with this character.
// Extract the last character of t and append u with this character.
// Petya wants to get strings s and t empty and string u lexicographically minimal.

// You should write a program that will help Petya win the game.

// Input
// First line contains non-empty string s (1 ≤ |s| ≤ 105), consisting of lowercase English letters.

// Output
// Print resulting string u.

// Examples
// input
// cab
// output
// abc
// input
// acdb
// output
// abdc

// -----------------------------------------------

// https://codeforces.com/contest/797/problem/C

// -----------------------------------------------

//More Explanation:
// The goal of the game is to make both s and t empty while making u lexicographically minimal.

// Here's an example to illustrate the game:

// Suppose the given string s is "acdb".

// Initially, s = "acdb", t = "", u = "".
// Petya extracts the first character 'a' from s and appends it to t. Now, s = "cdb", t = "a", u = "".
// Petya extracts the last character 'a' from t and appends it to u. Now, s = "cdb", t = "", u = "a".
// Petya extracts the first character 'c' from s and appends it to t. Now, s = "db", t = "c", u = "a".
// Petya extracts the last character 'c' from t and appends it to u. Now, s = "db", t = "", u = "ac".
// Petya extracts the first character 'd' from s and appends it to t. Now, s = "b", t = "d", u = "ac".
// Petya extracts the last character 'd' from t and appends it to u. Now, s = "b", t = "", u = "acd".
// Petya extracts the first character 'b' from s and appends it to t. Now, s = "", t = "b", u = "acd".
// Petya extracts the last character 'b' from t and appends it to u. Now, s = "", t = "", u = "acbd".
// The game ends when both s and t are empty. The resulting string u is "acbd", which is lexicographically minimal.

// So, the task is to write a program that helps Petya win the game by obtaining the resulting string u.

// -----------------------------------------------

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n = s.length();
    stack<int> st;
    vector<int> freq(26,0);
    vector<int> present(26,0);
    for(int i=0;i<n;i++)
        freq[s[i]-'a']++;

    string u = "";
    for(auto c:s)
    {
        freq[c-'a']--;
        if(present[c-'a'])
            continue;
        while(!st.empty() && st.top() > c && freq[st.top()-'a'])
        {
            u.push_back(st.top());
            st.pop();
            freq[c-'a']++;
        }
        st.push(c);
        present[c-'a'] = 1;

    }
    while(!st.empty())
    {
        u.push_back(st.top());
        st.pop();
    }

    cout<<u<<endl;


}