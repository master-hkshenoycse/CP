
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    
    void rec(Node *root,int &ans,int &len,int sum,int depth){
        if(root){
            depth=depth+1;
            sum=sum+root->data;
            //cout<<sum<<" "<<depth<<endl;
            if(root->left==NULL and root->right==NULL){
                if(len<depth){
                    len=depth;
                    ans=sum;
                }else if(len==depth){
                    ans=max(ans,sum);
                }
            }
            
            if(root->left){
                rec(root->left,ans,len,sum,depth);
            }
            
            if(root->right){
                rec(root->right,ans,len,sum,depth);
            }
            
        }
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int ans=0,len=0;
        rec(root,ans,len,0,0);
        return ans;
    }
};