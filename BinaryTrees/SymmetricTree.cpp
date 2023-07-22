/*
Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
https://leetcode.com/problems/symmetric-tree/description/
*/
//  * Definition for a binary tree node.
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
    bool areMirror(TreeNode* r1,TreeNode* r2)
    {
        if(!r1 && !r2)return true;
        if(!r1 || !r2)return false;
        return r1->val == r2->val && areMirror(r1->left,r2->right) && areMirror(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return areMirror(root->left,root->right);
    }
};