#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *build(int post_l,int post_r,int inorder_l,int inorder_r,int *post,map<int,int> &pos_in_inorder){
        
        if(post_r<post_l){
            return NULL;
        }
        
        int data=post[post_r];
        int p=pos_in_inorder[data];
        int sz_left=p-inorder_l;
        int sz_right=(inorder_r-inorder_l+1)-sz_left-1;
        
        
        Node *root=new Node(data);
        
        root->left=build(post_l,post_l+sz_left-1,inorder_l,p-1,post,pos_in_inorder);
        root->right=build(post_l+sz_left,post_r-1,p+1,inorder_r,post,pos_in_inorder);
        
        return root;
        
        
    }
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        map<int,int> pos_in_inorder;
        for(int i=0;i<n;i++){
            pos_in_inorder[in[i]]=i;
        }
        
        return build(0,n-1,0,n-1,post,pos_in_inorder);
    }
};