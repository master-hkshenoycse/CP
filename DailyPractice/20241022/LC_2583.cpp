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
 
#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<ll> lvl_sum;
        
        while(q.size()>0){
            ll sz=q.size();
            ll s=0;
            for(int i=0;i<sz;i++){
                auto v=q.front();
                q.pop();
                s=s+v->val;
                
                if(v->left){
                    q.push(v->left);
                }
                if(v->right){
                    q.push(v->right);
                }
                
            }
            
            lvl_sum.push_back(s);
        }
        
        sort(lvl_sum.begin(),lvl_sum.end());
        reverse(lvl_sum.begin(),lvl_sum.end());
        
        if(lvl_sum.size()<k){
            return -1;
        }
        
        return lvl_sum[k-1];
        
    }
};