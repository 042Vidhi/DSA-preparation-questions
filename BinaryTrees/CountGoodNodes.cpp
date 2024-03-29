/*
1448. Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree

https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
*/
#include<bits/stdc++.h>
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
    void dfs(TreeNode* root, int &count, int x) {
        if (!root) return;
        //check if root is good node
        if (root->val >= x) count++;
        //update x
        dfs(root->left, count, max(x, root->val));
        dfs(root->right, count, max(x, root->val));
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        if (!root) return count;

        dfs(root, count, root->val);
        return count;
    }
};
