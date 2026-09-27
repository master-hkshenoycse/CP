#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> tree;
    int n;
    void build(vector<int> &nums, int node, int l, int r){
        if(l==r){
            tree[node]=nums[l];
            return;
        }

        int mid=(l+r)/2;
        build(nums,node*2,l,mid);
        build(nums,node*2+1,mid+1,r);
        tree[node]=__gcd(tree[node*2],tree[node*2+1]);
    }

    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            tree[node]=val;
            return;
        }

        int mid=(l+r)/2;
        if(pos<=mid)
            update(node*2,l,mid,pos,val);
        else
            update(node*2+1,mid+1,r,pos,val);

        tree[node]=__gcd(tree[node*2],tree[node*2+1]);
    }

    int findLeft(int node, int l,int r, int target, int &cur){
        if(l==r)
            return l;
        
        int mid=(l+r)/2;
        int leftGcd = __gcd(cur,tree[node*2]);
    
        if(leftGcd == target)
            return findLeft(node*2, l, mid, target, cur);
        
        cur = leftGcd;

        return findLeft(node*2+1, mid+1, r, target, cur);
    }

    int findRight(int node, int l, int r, int target, int &cur){
        if(l==r)
            return l;
        int mid=(l+r)/2;

        int rightGcd = __gcd(cur, tree[node*2+1]);

        if(rightGcd == target)
            return findRight(node*2+1,mid+1,r,target,cur);
        
        cur=rightGcd;
        return findRight(node*2, l ,mid, target, cur);
    }
    int score(int ind_remove){
        int G=tree[1];
        int cur=0;
        int L=findLeft(1,0,n-1,G,cur);
        
        cur=0;
        int R=findRight(1,0,n-1,G,cur);

        if(ind_remove !=-1){
            if(ind_remove < L)  
                L--;
            
            if(ind_remove < R)
                R--;
        }

        return R-L;
    }
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        this->n =n;
        tree.assign(4*n,0);
        build(nums,1,0,n-1);

        int ans=max(0,score(-1));
    

        for(int i=0;i<n;i++){
            update(1,0,n-1,i,0);
            ans=max(ans,score(i));
            update(1,0,n-1,i,nums[i]);
        }

        return ans;
    }       
};