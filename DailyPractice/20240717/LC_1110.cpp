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
    TreeNode* rec(TreeNode *root,vector<TreeNode*> &sol,set<int> &delNodes,int is_root){
        if(root){

            int found=0;
            if(delNodes.find(root->val) != delNodes.end()){
                found=1;
            }
            int nx_is_root=0;
            if(found==0){
                if(is_root){
                    sol.push_back(root);
                }
            }else{
                nx_is_root=1;
            }

            root->left=rec(root->left,sol,delNodes,nx_is_root);
            root->right=rec(root->right,sol,delNodes,nx_is_root);

            if(found){
                return NULL;
            }else{
                return root;
            }

        }

        return NULL;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> is_not_present;
        for(auto tn:to_delete){
            is_not_present.insert(tn);
        }

        vector<TreeNode*> sol;
        rec(root,sol,is_not_present,1);

        return sol;

    }
};