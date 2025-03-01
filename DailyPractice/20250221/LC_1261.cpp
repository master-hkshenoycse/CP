

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<bits/stdc++.h>
using namespace std;
class FindElements {
    public:
        set<int> elements;
        void rec(TreeNode *root,int value){
            if(root==NULL){
                return;
            }
    
            elements.insert(value);
            rec(root->left,value*2+1);
            rec(root->right,value*2+2);
    
        }
        FindElements(TreeNode* root) {
            rec(root,0);
        }
        
        bool find(int target) {
            if(elements.find(target) != elements.end()){
                return true;
            }
    
            return false;
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */