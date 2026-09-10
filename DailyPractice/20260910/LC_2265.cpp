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
    pair<int,int> dfs(TreeNode *root){
        if(root){
            
            pair<int,int> l=dfs(root->left);
            pair<int,int> r=dfs(root->right);            
            pair<int,int> ret;
            
            ret.first=l.first+r.first;
            ret.second=l.second+r.second;
            ret.first++;
            ret.second+=root->val;
            
            if((root->val) == (ret.second/ret.first)){
                ans++;
            }
            
            
            
            return ret;   
        }
        return {0,0};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
        
    }
};