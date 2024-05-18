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

//counts how mant times a edge will be used
class Solution {
public:

    int ans=0;
    pair<int,int> get_diff(TreeNode *root){
        if(root==NULL){
            return {0,0};
        }

        auto l=get_diff(root->left);
        auto r=get_diff(root->right);

        int cnt_nodes=l.first+r.first+1;
        int cnt_coins=l.second+r.second+root->val;

        ans=ans+abs(cnt_coins-cnt_nodes);

        return {cnt_nodes,cnt_coins};
        
    }
    int distributeCoins(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        ans=0;
        get_diff(root);
        return ans;
    }
};