/*
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and 
the answer must be a reference to a node in the cloned tree.

https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/
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

    void ans(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& temp) {
        if (!original || !cloned) return;
        if (original == target) {
            temp = cloned;
            return;
        }
        ans(original->left, cloned->left, target, temp);
        ans(original->right, cloned->right, target, temp);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* temp = nullptr;
        ans(original, cloned, target, temp);
        return temp;
    }
};
