/*
110. Balanced Binary Tree

Given a binary tree, determine if it is 
height-balanced
.

https://leetcode.com/problems/balanced-binary-tree/description/
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
    int heightBalanced(TreeNode* root)
    {
        if(root == NULL) return 0;
        int left = heightBalanced(root->left);
        int right = heightBalanced(root->right);
        if(left == -1 || right == -1)return -1;
        if(abs(left-right)>1)return -1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(heightBalanced(root)==-1) return false;
        return true;
    }
};