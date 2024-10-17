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
    vector<int> dfs(TreeNode *root,vector<int> &sz_subtree){
        if(root==NULL){
            return {0,1};
        }
        vector<int> lf=dfs(root->left,sz_subtree);
        vector<int> rf=dfs(root->right,sz_subtree);
        vector<int> ret={0,0};
        if(lf[1]==1 and rf[1]==1 and lf[0]==rf[0]){            
            ret[0]=lf[0]+rf[0]+1;
            ret[1]=1;
            //cout<<ret[0]<<" "<<ret[1]<<endl;
            sz_subtree.push_back(ret[0]);
        }
        return ret;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sz_subtree;
        dfs(root,sz_subtree);
        sort(sz_subtree.begin(),sz_subtree.end());
        reverse(sz_subtree.begin(),sz_subtree.end());
        if(sz_subtree.size()<k){
            return -1;
        }

        return sz_subtree[k-1];
    }
};