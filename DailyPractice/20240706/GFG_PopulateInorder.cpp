#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = null;
        right = null;
        next = null;
    }
};

class Solution {
  public:

    void populateNext(Node *root) {
        // code here
        Node *prev=null;
        while(root){
            if(root->left==null){
            
                if(prev){
                    prev->next=root;
                }
                prev=root;
                root=root->right;
                
                
            }else{
                Node *tmp=root->left;
                while(tmp->right and tmp->right!=root){
                    tmp=tmp->right;
                }
                
                if(tmp->right==NULL){
                    tmp->right=root;
                    root=root->left;
                }else{

                    root=tmp->right;
                    tmp->right=NULL;

                    if(prev){
                        prev->next=root;
                    }
                    prev=root;
                    root=root->right;
                }
                
            }
        }
    }
};