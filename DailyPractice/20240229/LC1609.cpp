

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
    bool isEvenOddTree(TreeNode* root) {
        int level=0;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()>0){
            int sz=q.size();
            vector<int> tmp;

            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();

                tmp.push_back(node->val);
                if(level ^ ((node->val)%2) ){
                    
                }else{
                    return 0;
                }
                
                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            

            if(level==0){
                for(int i=1;i<sz;i++){
                    if(tmp[i]<=tmp[i-1]){
                        return 0;
                    }
                }
            }else{
                for(int i=1;i<sz;i++){
                    if(tmp[i]>=tmp[i-1]){
                        return 0;
                    }
                }
            }


            level=1-level;
        }

        return 1;
    }
};