#include<bits/stdc++.h>
using namespace std;

 // Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*https://leetcode.com/problems/find-bottom-left-tree-value/?envType=daily-question&envId=2024-02-28*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        int ans=-1;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()>0){
            int sz=q.size();

            for(int i=0;i<sz;i++){
                TreeNode *curr=q.front();
                q.pop();

                if(i==0){
                    ans=curr->val;
                }

                if(curr->left){
                    q.push(curr->left);
                }

                if(curr->right){
                    q.push(curr->right);
                }

            }
        }

        return ans;

    }
};