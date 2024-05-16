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
    bool evaluateTree(TreeNode* root) {
        if(root->left and root->right){
            int res_l=evaluateTree(root->left);
            int res_r=evaluateTree(root->right);
            int v=root->val;

            if(v==2){
                return res_l or res_r;
            }else{
                return res_l and res_r;
            }

        }else{
            return root->val;
        }
    }
};