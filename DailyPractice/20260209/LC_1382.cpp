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
    void rightRotate(TreeNode *parent,TreeNode *node){
        TreeNode *tmp=node->left;
        node->left = tmp->right;
        tmp->right = node;
        parent->right = tmp;
    }

    void leftRotate(TreeNode *parent,TreeNode *node){
        TreeNode *tmp=node->right;
        parent->right = tmp;
        node->right = tmp->left;
        tmp->left = node;
    }

    void makeRotation(TreeNode *head,int count){
        TreeNode *current = head;
        for(int i=0;i<count;i++){
            TreeNode *tmp = current->right;
            leftRotate(current,tmp);
            current = current->right;
        }
    }

    int getCnt(TreeNode *head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->right;
        }
        return cnt-1;
    }
    
    void getVine(TreeNode *root){
        while(root->right){
            if(root->right->left){
                rightRotate(root,root->right);
            }else{
                root=root->right;
            }
        }
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode *vineHead = new TreeNode(0);
        vineHead->right = root;
        getVine(vineHead);


        int cnt=getCnt(vineHead);
        int m=pow(2,floor(log2(cnt+1)))-1;

        makeRotation(vineHead,cnt-m);
        while(m>1){
            m/=2;
            makeRotation(vineHead,m);
        }

        return vineHead->right;

    }
};