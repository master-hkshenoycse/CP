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
    int ans=0;
    void rec(TreeNode *root,int x){
        int v=root->val;
        x=x*2+v;
        
        if(root->left==NULL and root->right==NULL){
            ans=ans+x;
            return;
        }
        
        if(root->left){
            rec(root->left,x);
        }
        
        if(root->right){
            rec(root->right,x);
        }
        
    }
    int sumRootToLeaf(TreeNode* root) {
        rec(root,0);
        return ans;
    }
};