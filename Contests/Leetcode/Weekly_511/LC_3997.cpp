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
    int rec(TreeNode *root,int &ans){
        if(root==NULL)
            return 0;
        
        int lf=rec(root->left,ans);
        int rf=rec(root->right,ans);
        
        int ret=max({lf,rf,root->val});
        if(ret==root->val)
            ans++;
        
        return ret;
    }
    int countDominantNodes(TreeNode* root) {
        int ans=0;
        rec(root,ans);
        return ans;
    }
};