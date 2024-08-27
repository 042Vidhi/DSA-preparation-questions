#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //using bfs
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(endWord==word)return steps;
            for(int i =0;i<word.size();i++)
            {
                char original = word[i];
                //make combinations of diff words
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        //first erase that word from set
                        st.erase(word);
                        //new word is present in the list then add it to queue and inc step
                        q.push({word,steps+1});
                    }
                }
                //make the word original
                word[i]=original;
            }


        }
        return 0;

    }
};