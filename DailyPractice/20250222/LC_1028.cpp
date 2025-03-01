

 
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
        TreeNode *rec(vector<int> &order,int &index,int depth){
            
            TreeNode *root=new TreeNode(order[index]);
    
            if(index+1<order.size() && depth+1==order[index+1]){
                int value=order[index+2];
                index+=2;
                root->left=rec(order,index,depth+1);
            }
    
    
            if(index+1<order.size() && depth+1==order[index+1]){
                int value=order[index+2];
                index+=2;
                root->right=rec(order,index,depth+1);
            }
    
    
    
            return root;
        }
        TreeNode* recoverFromPreorder(string traversal) {
            TreeNode *root=NULL;
    
            vector<int> order;
            int i=0,n=traversal.size();
    
            while(i<n){
                int j=i;
                if(traversal[j]=='-'){
                    int c=0;
                    while(j<n and traversal[j]=='-'){
                        c++;
                        j++;
                    }
                    order.push_back(c);
                }else{
                    int val=0;
                    while(j<n and traversal[j]>='0' &&  traversal[j]<='9'){
                        val=val*10+(traversal[j]-'0');
                        j++;
                    }
                    order.push_back(val);
                }
                i=j;
            }
    
            
            int index=0;
            return rec(order,index,0);
    
        }
    };