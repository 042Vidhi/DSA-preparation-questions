/*
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return 1;
        int level=INT_MAX;
        if(root->right)
        {
            level = min(minDepth(root->right),level);
        }
        if(root->left)
        {
            level = min(minDepth(root->left),level);
        }
        return level+1;
    }
};