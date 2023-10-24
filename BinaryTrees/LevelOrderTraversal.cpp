/*
110.Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values.
 (i.e., from left to right, level by level).

https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
  };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        //using queue of pair
        queue<pair<TreeNode*,int>>q;
        int level = 0;
        q.push({root,level});
        while(!q.empty())
        {
            //pop the root 
            pair<TreeNode*,int> temp = q.front();
            q.pop();
            if(temp.second >= ans.size())
            {
                ans.push_back({temp.first->val});
            }
            else{
                ans[temp.second].push_back(temp.first->val);
            }
            level = temp.second + 1;
            if(temp.first->left) q.push({temp.first->left,level});
            if(temp.first->right) q.push({temp.first->right,level});
        }  
        return ans;
    }
};