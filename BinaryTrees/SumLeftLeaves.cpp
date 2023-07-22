/*
404. Sum of Left Leaves
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
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
    void recursum(TreeNode* root,int &sum)
    {
        if(!root)return ;

        if(root->left && !root->left->right && !root->left->left )
        {
            sum+= root->left->val;
        }

        recursum(root->left,sum);
        recursum(root->right,sum);


    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        recursum(root,sum);
        return sum;
    }
};