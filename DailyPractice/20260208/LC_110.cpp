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
    bool sol=1;
    int helper(TreeNode *root){
        if(root==NULL)return 0;
        int h1=helper(root->left);
        int h2=helper(root->right);
        
        if(abs(h1-h2) > 1){
            sol=0;
        }
        
        return 1+max(h1,h2);
    }
    bool isBalanced(TreeNode* root) {
    
        helper(root);
        return sol;
    }
};