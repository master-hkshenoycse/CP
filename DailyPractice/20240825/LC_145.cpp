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
    void rec(TreeNode *root,vector<int> &sol){
        if(root){
            rec(root->left,sol);
            rec(root->right,sol);
            sol.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> sol;
        rec(root,sol);

        return sol;
    }
}