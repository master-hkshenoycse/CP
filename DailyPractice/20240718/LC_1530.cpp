
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
     
    vector<int> leafs(TreeNode *root,int distance,int &ans){
        vector<int> ret;

        if(root){

            auto left_leaves=leafs(root->left,distance,ans);
            auto right_leaves=leafs(root->right,distance,ans);

            for(auto l:left_leaves){
                for(auto r:right_leaves){
                    if(l+r+2<=distance){
                        ans++;
                    }
                }
            }

            for(auto l:left_leaves){
                ret.push_back(l+1);
            }

            for(auto r:right_leaves){
                ret.push_back(r+1);
            }

            if(ret.size()==0){
                ret.push_back(0);
            }

        }

        return ret;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans=0;

        leafs(root,distance,ans);

        return ans;

    }
};