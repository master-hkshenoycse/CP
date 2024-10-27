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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        root->val=0;
        int tot_sum=0;

        while(q.size()>0){
            int sz=q.size(),nx_sum=0;
            for(int i=0;i<sz;i++){
                TreeNode *curr=q.front();
                q.pop();
                curr->val+=tot_sum;
                int og_left=-1,og_right=-1;

                if(curr->left){
                    nx_sum+=curr->left->val;
                    og_left=curr->left->val;
                    q.push(curr->left);
                }

                if(curr->right){
                    nx_sum+=curr->right->val;
                    og_right=curr->right->val;
                    q.push(curr->right);
                }

                if(og_left != -1){
                    curr->left->val=-og_left;
                    if(og_right != -1){
                        curr->left->val-=og_right;
                    }
                }

                if(og_right!=-1){
                    curr->right->val=-og_right;
                    if(og_left != -1){
                        curr->right->val-=og_left;
                    }
                }
            }

            tot_sum=nx_sum;

        }


        return root;
    }
};