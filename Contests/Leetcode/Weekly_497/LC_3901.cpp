#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> seg_tree;
    void build(int ind,int l, int r, vector<int> &nums,int p){
        if(l>r)
            return;
        
        if(l==r){
           seg_tree[ind]=(nums[l]%p==0?nums[l]/p:0);
           
           return;
        }

        int mid=(l+r)/2;
        build(ind*2,l,mid,nums,p);
        build(ind*2+1,mid+1,r,nums,p);
        seg_tree[ind]=__gcd(seg_tree[ind*2],seg_tree[ind*2+1]);
    }
    void update(int ind,int l,int r,int idx,int val,int p){
        if(l==r){
            seg_tree[ind]=(val%p==0?val/p:0);
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid)
            update(ind*2,l,mid,idx,val,p);
        else
            update(ind*2+1,mid+1,r,idx,val,p);
        
        seg_tree[ind]=__gcd(seg_tree[ind*2],seg_tree[ind*2+1]);
    }
    bool canExcludeOne(int ind,int l,int r,int ext){
        if(l==r)
            return ext==1;
        
        int mid=(l+r)/2;
        int left=__gcd(ext,seg_tree[ind*2+1]);
        int right=__gcd(ext,seg_tree[ind*2]);

        if(left==1 || right==1)
            return true;
        
        return canExcludeOne(ind*2,l,mid,left) || canExcludeOne(ind*2+1,mid+1,r,right);
    }
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        int n=nums.size();
        seg_tree.assign(4*n,0);
        int cnt=0;
        for(auto e:nums)
            cnt+=((e%p)==0);
        
        build(1,0,n-1,nums,p);

        int ans=0;
        for(auto q:queries){
            int idx=q[0];
            int val=q[1];

            if(nums[idx]%p==0)cnt--;
            if(val%p==0)cnt++;

            nums[idx]=val;
            update(1,0,n-1,idx,val,p);

            if(seg_tree[1]==1){
                if(cnt<n)ans++;
                else if(canExcludeOne(1,0,n-1,0))ans++;
            }
        }
 
        return ans;
    }
};