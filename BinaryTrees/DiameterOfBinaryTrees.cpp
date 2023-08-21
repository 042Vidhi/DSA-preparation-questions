/*
543. Diameter of Binary Tree

*/


//Brute Force
//Time Complexity: O(n^2)
//Space Complexity: O(n)
//return max(Height(root->left) + Height(root->right) + 1, max(Diameter(root->left), Diameter(root->right)));

//Optimized
//Time Complexity: O(n)
//Space Complexity: O(n)

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


//Brute Force
// class Solution {
// public:
//     int height(TreeNode* root)
//     {
//         if(!root)return 0;
//         int l=height(root->left);
//         int r=height(root->right);
//         return max(r,l)+1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         //brute-force
//         if(!root)return 0;
//         int l = diameterOfBinaryTree(root->left);
//         int r = diameterOfBinaryTree(root->right);

//         int h = height(root->left) + height(root->right);

//         return max(h,max(l,r));
//     }
// };  


//Optimized
class Solution {
    pair<int , int> fun(TreeNode* root){
        if(!root) return {0 , 0};
 
        pair<int , int> left = fun(root->left);
        pair<int, int> right = fun(root->right);
 
        int dia = max(max(left.first , right.first) , 
        1 + left.second + right.second);
 
        int height = 1 + max(left.second , right.second);
 
        return {dia , height};
    }
    int diameterOfBinaryTree(TreeNode* root) {  
        pair<int , int> p = fun(root);
        return p.first - 1 ;
    }
};