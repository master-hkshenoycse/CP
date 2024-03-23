#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:

    int get_sol(TreeNode *root,int &ans){
        if(root==NULL){
            return 0;
        }

        int lf=get_sol(root->left,ans);
        int rf=get_sol(root->right,ans);
        ans=max(ans,lf+rf);


        return max(lf,rf)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        get_sol(root,ans);
        return ans;
    }
};

/*https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27*/