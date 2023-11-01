/*
501. Find Mode in Binary Search Tree

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) 
(i.e., the most frequently occurred element) in it.

https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorderTraversal(TreeNode* root,vector<int>& nodeList)
    {
        if(root==NULL)
        return;

        inorderTraversal(root->left,nodeList);
        nodeList.push_back(root->val);
        inorderTraversal(root->right,nodeList);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> nodeList;

        inorderTraversal(root,nodeList);
        unordered_map<int,int> mp;
        int maxfreq =INT_MIN;
        for (int i = 0; i < nodeList.size(); i++) {
            mp[nodeList[i]]++;
            maxfreq = max(maxfreq, mp[nodeList[i]]);
        }

        vector<int> ans;
        for(auto i:mp)
        {
            if(maxfreq==i.second)
            {
                ans.push_back(i.first);
            }
        }

        return ans;
        
    }
};
