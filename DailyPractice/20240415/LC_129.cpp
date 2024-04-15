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
    void rec(TreeNode *root,int &ans,int curr){
        if(root==NULL){
            return;
        }

        curr=curr*10+root->val;
        if(root->left==NULL and root->right==NULL){
            ans=ans+curr;
            return;
        }

        rec(root->left,ans,curr);
        rec(root->right,ans,curr);

        
    }
    int sumNumbers(TreeNode* root) {
        int ans=0,curr=0;
        rec(root,ans,curr);
        return ans;

    }
};