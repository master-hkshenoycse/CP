
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        TreeNode *getLca(TreeNode *root,TreeNode *a,TreeNode *b){
            if(root == NULL){
                return NULL;
            }
    
            if(root->val == a->val || root->val == b->val){
                return root;
            }
    
            TreeNode *lf=getLca(root->left,a,b);
            TreeNode *rf=getLca(root->right,a,b);
    
            if(lf && rf){
                return root;
            }
    
            if(lf){
                return lf;
            }
    
            return rf;
        }
    
        void dfs(TreeNode *root,int d,int &maxDepth,vector<TreeNode *> &deepLeaves){
            if(d>maxDepth){
                deepLeaves.clear();
                maxDepth=d;
            }
    
            if(d==maxDepth){
                deepLeaves.push_back(root);
            }
    
            if(root->left){
                dfs(root->left,d+1,maxDepth,deepLeaves);
            }
    
            if(root->right){
                dfs(root->right,d+1,maxDepth,deepLeaves);
            }
    
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            vector<TreeNode *> deepLeaves;
            int maxDepth=-1;
    
            dfs(root,0,maxDepth,deepLeaves);
    
            int sz=deepLeaves.size();
            TreeNode *lca=deepLeaves[0];
    
            for(int i=1;i<sz;i++){
                lca=getLca(root,lca,deepLeaves[i]);
            }
    
            return lca;
        }
    };