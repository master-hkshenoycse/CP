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
    
    void change_tree(TreeNode *root,int v,int d,int cd){
        if(root == NULL)return ;
        if(d-2==cd){
            
            TreeNode *l=root->left;
            TreeNode *r=root->right;
            
            root->left=new TreeNode(v);
            root->right=new TreeNode(v);
            
            root->left->left=l;
            root->right->right=r;
            
            return;
        }
        change_tree(root->left,v,d,cd+1);
        change_tree(root->right,v,d,cd+1);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        
        if(d>=2)change_tree(root,v,d,0);
        else{
            TreeNode *c=new TreeNode(v);
            c->left=root;
           
            return c;
        }
        return root;
    }
};