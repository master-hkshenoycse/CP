
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> sol;
        if(root==NULL){
            return sol;
        }
        while(q.size()>0){
            int sz=q.size(),ma=INT_MIN;
            for(int i=0;i<sz;i++){
                TreeNode *curr=q.front();
                q.pop();

                ma=max(ma,curr->val);
                if(curr->left){
                    q.push(curr->left);
                }

                if(curr->right){
                    q.push(curr->right);
                }
            }
            sol.push_back(ma);
        }

        return sol;
    }
};