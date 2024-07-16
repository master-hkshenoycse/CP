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
    vector<pair<int,int> > adj[100005];
    int is_child[100005],is_ele[100005]; 
    TreeNode *get_tree(int val){
        TreeNode *root=new TreeNode(val);
        
        for(auto to:adj[val]){
            if(to.second==1){
                root->left=get_tree(to.first);
            }else{
                root->right=get_tree(to.first);
            }
        }
            
            
            
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        
        for(auto d:descriptions){
            is_child[d[1]]=1;
            is_ele[d[0]]=1;
            is_ele[d[0]]=1;
            
            adj[d[0]].push_back({d[1],d[2]});
            
        }
        
        int root_ele=-1;
        for(int i=1;i<=100000;i++){
            if(is_ele[i]>0 and is_child[i]==0){
                root_ele=i;
                break;
            }
        }
        
        return get_tree(root_ele);
    }
};