
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
 

// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root){
        // your code here
        
        
        stack<Node *> st;
        Node *prev=NULL,*sol=NULL;
        
        while(st.size()>0 or root){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            
            if(prev==NULL){
                sol=root;
            }
            
            root->left=prev;
            if(prev){
                prev->right=root;
            }
            
            prev=root;
            root=root->right;
        
            
        }
        
        return sol;
    }
};