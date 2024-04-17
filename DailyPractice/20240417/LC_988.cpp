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
    
    void search(TreeNode* root,string &x,string &ans){
        if(root){

            //put character in x
            char ch=char('a'+root->val);
            x+=ch;

            if(root->left==NULL and root->right==NULL){
                string tmp=x;
                reverse(tmp.begin(),tmp.end());
                if(ans.size()==0){
                    ans=tmp;
                }else{
                    ans=min(ans,tmp);
                }
            }

            search(root->left,x,ans);
            search(root->right,x,ans);

            //backtrack the added character
            x.pop_back();
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string y,ans;
        search(root,y,ans);

        return ans;
        
    }
};