

struct TreeNode {
  int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(q.size()>0){
            vector<int> a,b;
            int sz=q.size();
            
            
            for(int i=0;i<sz;i++){
                a.push_back(q.front()->val);
                b.push_back(q.front()->val);
                
                auto v=q.front();
                q.pop();
                
                if(v->left){
                    q.push(v->left);
                }
                
                if(v->right){
                    q.push(v->right);
                }
                
            }
            
            sort(b.begin(),b.end());
            map<int,int> pos;
            
            int c=0;
            for(int i=0;i<sz;i++){
                pos[a[i]]=i;
            }
            
            for(int i=0;i<sz;i++){
                if(a[i]==b[i]){
                    continue;
                }
                int ind=pos[b[i]];
                pos[a[i]]=ind;
                pos[a[ind]]=i;
                swap(a[i],a[ind]);
                ans++;
            }
        }
        return ans;
        
    }
};