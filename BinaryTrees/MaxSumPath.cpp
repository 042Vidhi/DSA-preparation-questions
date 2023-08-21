/*


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
   pair<int , int>fun(TreeNode* root){
        if(!root) return {INT_MIN , INT_MIN};
 
        pair<int , int> left = fun(root->left);
        pair<int , int> right = fun(root->right);
 
        int ans = max( max( root->val + max(0 , left.second ) + max(0 , right.second) ,
                left.first) ,
                right.first
        );
 
        int maxSumUniPAth = root->val + max( {0 , 
        left.second , right.second});
 
        return {ans , maxSumUniPAth};
    }
    int maxPathSum(TreeNode* root) {
        pair<int , int> p = fun(root);
        return p.first;
    }

};