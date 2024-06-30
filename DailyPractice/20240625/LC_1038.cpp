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
    void rec(TreeNode *root,int &sum){
        if(root){
            rec(root->right,sum);
            int tmp=root->val;
            root->val+=sum;
            sum+=tmp;
            rec(root->left,sum);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        rec(root,sum);
        return root;
    }
};