#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
public:
    
    Node *flattenBST(Node *root){
        // code here
        if(root==NULL){
            return root;
        }
        
        Node *leftList=flattenBST(root->left);
        Node *rightList=flattenBST(root->right);
        
        Node *prev=NULL,*tmp=leftList;
        
        while(tmp){
            prev=tmp;
            tmp=tmp->right;
        }
        
        if(prev != NULL){
            leftList->left=NULL;
            prev->right=root;
            root->left=NULL;
            root->right=rightList;
            return leftList;
        }
        
        root->right=rightList;
        return root;
    }
};

void print(Node* parent)
{
    Node* curr = parent;
    while (curr != NULL){
        cout << curr->data << " ", curr = curr->right;
    }
}
int main(){

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    
    Solution sol;
    // Calling required function
    print(sol.flattenBST(root));
}
/*https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/ */