/*
515. Find Largest Value in Each Tree Row
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
    vector<int> largestValues(TreeNode* root) {
        //using bfs -> queues
        vector<int> result;
        queue<TreeNode*> q;

        if(root == NULL) return result;

        //bfs starts
        q.push(root);

        while(!q.empty())
        {
            //number of children in each row
            int x = q.size();
            int row_max = INT_MIN;
            while(x--)
            {
                TreeNode* curr = q.front();
                row_max=max(row_max,curr->val);
                q.pop();
                //add chilren of the node to queue
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            result.push_back(row_max);        
        }

        return result;
    }
};