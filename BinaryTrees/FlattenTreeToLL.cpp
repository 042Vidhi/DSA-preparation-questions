/*

*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while(cur!=NULL)
        {
            //if cur ka left exist 
            if(cur->left)
            {
                TreeNode *prev = cur->left;
                while(prev->right)
                    prev=prev->right;
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur -> right;
        }
    }
};