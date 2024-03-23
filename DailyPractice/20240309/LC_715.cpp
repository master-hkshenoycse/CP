#include<bits/stdc++.h>
using namespace std;



class Node{
    public:
    int l,r;
    bool state;

    Node *left=NULL,*right=NULL;

    Node(int l,int r,bool st){
        this->l=l;
        this->r=r;
        this->state=st;
    }
};
/*https://leetcode.com/problems/range-module/solutions/3473151/clean-and-elegant-segment-tree-on-interval/*/
class RangeModule {
public:
    
    Node *root;

    RangeModule() {
        root=new Node(0,1e9,false);
    }

    bool update(int l,int r,bool state,Node *root){
        if(root->l >=l and root->r <= r){
            root->state=state;
            root->left=NULL;
            root->right=NULL;
            return state;
        }

        if(l >= root->r or r<=root->l){
            return root->state;
        }

        int mid=(root->l)+(root->r-root->l)/2;

        if(root->left==NULL){
            root->left=new Node(root->l,mid,root->state);
            root->right=new Node(mid,root->r,root->state);
        }

        bool left=update(l,r,state,root->left);
        bool right=update(l,r,state,root->right);

        root->state=left & right;
        return root->state;

    }
    void addRange(int left, int right) {
        update(left,right,true,root);
    }
    bool query(Node *root,int l,int r){
        if((root->l >=l and root->r <=r) || root->left==NULL){
            return root->state;
        }

        int mid=(root->l)+(root->r-root->l)/2;
        if(r<=mid){
            return query(root->left,l,r);
        }else if(l>=mid){
            return query(root->right,l,r);
        }else{  
            return query(root->left,l,r) && query(root->right,l,r);
        }
    }
    bool queryRange(int left, int right) {
        return query(root,left,right);
    }

    
    
    void removeRange(int left, int right) {
        update(left,right,false,root);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */