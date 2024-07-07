#include<bits/stdc++.h>
using namespace std;
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};


class Solution {
  public:
    // Function should return all the ancestor of the target node
    
    int rec(Node *root,vector<int> &sol,int target){
        if(root==NULL){
            return 0;
        }
        
        if(root->data==target){
            return 1;
        }
        
        int l=rec(root->left,sol,target);
        int r=rec(root->right,sol,target);
        
        if(l or r){
            sol.push_back(root->data);
        }
        
        return l or r;
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> sol;
        
        rec(root,sol,target);
        
        return sol;
    }
};