/*
257. Binary Tree Paths
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
https://leetcode.com/problems/binary-tree-paths/description/
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
    void dfs(TreeNode* root,string path,vector<string> &result)
    {
        if(!root) return;
        //if reached leaf node there will be no arrow -> 
        if(root->left==NULL && root->right==NULL)
        {
            path+=to_string(root->val);
            result.push_back(path);
        }
        //if not keep adding node to the path
        path+=to_string(root->val) + "->";
        dfs(root->left,path,result);
        
        dfs(root->right,path,result);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return {""};
        vector<string> result;
        string path="";
        dfs(root,path,result);
        return result;
    }
};