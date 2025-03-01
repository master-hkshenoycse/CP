#include<bits/stdc++.h>
using namespace std;

  Definition for a binary tree node.
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
        vector<int> pos_in_pre,pos_in_post;
        TreeNode *get_tree(vector<int>& preorder, vector<int>& postorder,int pre_start,int post_start,int post_end){
            if(post_start > post_end){
                return NULL;
            }
    
            TreeNode *root=new TreeNode(preorder[pre_start]);
            if(post_start == post_end){
                return root;
            }
            int left_pre=preorder[pre_start+1];
            int left_post_end=pos_in_post[left_pre];
            root->left=get_tree(preorder,postorder,pre_start+1,post_start,left_post_end);
            root->right=get_tree(preorder,postorder,pos_in_pre[postorder[post_end-1]],left_post_end+1,post_end-1);
            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n=preorder.size();
            pos_in_pre.assign(n+1,-1);
            pos_in_post.assign(n+1,-1);
    
            for(int i=0;i<n;i++){
                pos_in_pre[preorder[i]]=i;
                pos_in_post[postorder[i]]=i;
            }
    
            return get_tree(preorder,postorder,0,0,n-1);
        }
    };