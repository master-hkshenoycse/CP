#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
    bool helper(ListNode *head,TreeNode*root){
        if(head==NULL){
            return 1;
        }
        if(root==NULL){
            return 0;
        }
        
        if(root->val == head->val){
            return helper(head->next,root->left) or helper(head->next,root->right);
        }
            
        return 0;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(root==NULL and head==NULL){
            return 1;
        } 
        
        if(root==NULL and head){
            return 0;
        }
        return helper(head,root) or isSubPath(head,root->left) or isSubPath(head,root->right);
    }
};