#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};


class Solution
{
    public:
    
    /*You are required to complete below function */
    Node* get_lca(Node *root,int x,int y){
        if(root==NULL){
            return root;
        }
        
        if(root->data==x or root->data==y){
            return root;
        }
        
        Node *l=get_lca(root->left,x,y);
        Node *r=get_lca(root->right,x,y);
        
        if(l!=NULL and r!=NULL){
            return root;
        }
        
        if(l){
            return l;
        }
        
        return r;
    }
    
    int get_kth(Node *root,int lca,int &ans,int k){
        if(lca==root->data){
            
            if(k==1){
                ans=root->data;
            }
            
            return 1;
        }
        
        int d=0;
        if(root->data > lca){
            d=1+get_kth(root->left,lca,ans,k);
        }else{
            d=1+get_kth(root->right,lca,ans,k);
        }
        
        if(d==k){
            ans=root->data;
        }
        
    }
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        int lca=get_lca(root,x,y)->data;
        
        int ans=-1;
        get_kth(root,lca,ans,k);
        return ans;
    }
};
