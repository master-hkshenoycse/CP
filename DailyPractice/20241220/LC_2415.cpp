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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int lv=0;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()>0){
            vector<TreeNode *> seq;
            vector<int> values;
            int sz=q.size();
            while(sz--){
                TreeNode *curr=q.front();
                q.pop();


                seq.push_back(curr);
                values.push_back(curr->val);

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

            }


            if(lv){
                
                for(auto &s:seq){
                    s->val=values.back();
                    values.pop_back();
                }

            }

            lv=1-lv;
        }

        return root;
    }
};