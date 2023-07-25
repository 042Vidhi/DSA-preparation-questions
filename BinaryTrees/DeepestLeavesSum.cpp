/*
1302. Deepest Leaves Sum

Given the root of a binary tree, return the sum of values of its deepest leaves.
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
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
    void dfs(TreeNode* root,int &sum,int &maxdepth,int depth)
    {
        if(!root) return;
        depth += 1;
        if(!root->left && !root->right && depth==maxdepth)
        {
            sum+=root->val;
        }
        dfs(root->left,sum,maxdepth,depth);
        dfs(root->right,sum,maxdepth,depth);
    }
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int maxdepth =maxDepth(root);
        int depth =0;
        dfs(root,sum,maxdepth,depth);
        return sum;
    }
};
