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
    bool check(TreeNode *r1,TreeNode *r2){
        if(r1==NULL and r2==NULL){
            return 1;
        }

        if(r1==NULL or r2==NULL){
            return 0;
        }

        if(r1->val != r2->val){
            return 0;
        }

        return (check(r1->left,r2->left) and check(r1->right,r2->right)) or
         (check(r1->right,r2->left) and check(r1->left,r2->right));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1,root2);
    }
};