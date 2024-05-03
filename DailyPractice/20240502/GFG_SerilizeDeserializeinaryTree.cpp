#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> ret;
        if(root==NULL){
            return ret;
        }
        
        queue<Node *> q;
        ret.push_back(root->data);
        q.push(root);
        
        while(q.size()>0){
            auto curr=q.front();
            q.pop();
            
            
            
            if(curr->left==NULL){
                ret.push_back(-1);
            }else{
                ret.push_back(curr->left->data);
                q.push(curr->left);
            }
            
            if(curr->right==NULL){
                ret.push_back(-1);
            }else{
                ret.push_back(curr->right->data);
                q.push(curr->right);
            }
            
        }
        
        return ret;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if(A.size()==0){
           return NULL;
       }
       Node *root=new Node(A[0]);
       queue<Node *> q;
       q.push(root);
       
       int i=1;
       
       while(i<A.size()){
           Node *curr=q.front();
           q.pop();
           
           if(A[i]!=-1){
               curr->left=new Node(A[i]);
               q.push(curr->left);
           }
           
           i++;
           
           if(A[i] != -1){
               curr->right=new Node(A[i]);
               q.push(curr->right);
           }
           
           i++;
       }
       
       return root;
       
    }

};