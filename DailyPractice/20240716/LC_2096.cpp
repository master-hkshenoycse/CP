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
    
    string tmp;
    
    TreeNode *get_lca(TreeNode *root,int x,int y){
        if(root==NULL){
            return NULL;
        }
        if(root->val==x or root->val==y){
            return root;
        }
        
        TreeNode *l=get_lca(root->left,x,y);
        TreeNode *r=get_lca(root->right,x,y);
        
        if(l and r){
            return root;
        }
        
        if(l){
            return l;
        }
        return r;
    }
    
    int get_path(TreeNode *root,int x){
        
        if(root==NULL){
            return -1;
        }
        
        if(root->val==x){
            return 1;
        }
        
        int l=get_path(root->left,x);
        int r=get_path(root->right,x);
        
        if(l>0 or r>0){
            if(l>0){
                tmp+='L';
            }else{
                tmp+='R';
            }
            return max(l,r)+1;
        }
        
        return -1;
        
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca=get_lca(root,startValue,destValue);
        
        string sol;
        tmp.clear();
        
        if(lca->val==startValue){
            
            get_path(lca,destValue);
            sol=tmp;
            reverse(sol.begin(),sol.end());
            
        }else if(lca->val==destValue){
            
            get_path(lca,startValue);
            int sz=tmp.size();
            for(int i=0;i<sz;i++){
                sol+='U';
            }
            
        }else{
            
            get_path(lca,startValue);
            
            int sz=tmp.size();
            for(int i=0;i<sz;i++){
                sol+='U';
            }
            tmp.clear();
            
            
            get_path(lca,destValue);
            reverse(tmp.begin(),tmp.end());
            sol+=tmp;
            
            
        }
        
        
        return sol;
        
    }
};