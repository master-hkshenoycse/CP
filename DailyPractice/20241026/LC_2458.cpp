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
    int timer=0;
    int in_time[200005],out_time[200005];
    int cum_h_pref[200005],cum_h_suff[200005];
    
    void dfs(TreeNode *root,int h){
        int v=root->val;
        
        timer++;
        in_time[v]=timer;
        cum_h_pref[in_time[v]]=h;
        cum_h_suff[in_time[v]]=h;
        
        if(root->left){
            dfs(root->left,h+1);
        }
        
        if(root->right){
            dfs(root->right,h+1);
        }
        
        out_time[v]=timer;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        timer=0;
        dfs(root,0);
        
        cum_h_suff[timer+1]=0;
        for(int i=1;i<=timer;i++){
            cum_h_pref[i]=max(cum_h_pref[i],cum_h_pref[i-1]);
        }
        
        for(int i=timer;i>=1;i--){
            cum_h_suff[i]=max(cum_h_suff[i],cum_h_suff[i+1]);
        }
        
        
        vector<int> sol;
        for(auto q:queries){
            int l=in_time[q];
            int r=out_time[q];
            sol.push_back(max(cum_h_pref[l-1],cum_h_suff[r+1]));
        }
        
        return sol;
    
    }
};