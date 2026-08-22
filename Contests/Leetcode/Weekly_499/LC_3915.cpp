#include<bits/stdc++.h>
using namespace std;
#define ll long long
class segTree{
    private:
        vector<ll> seg_tree;
    public:
        segTree(int n){
            seg_tree.resize(4*n+1,-1);
        }

        void update(int node, int l,int r,int ind, ll val){
            if(l>r)
                return;
            
            if(l==r){
                seg_tree[node]=val;
                return;
            }

            int mid=(l+r)/2;
            if(ind<=mid)
                update(node*2,l,mid,ind,val);
            else 
                update(node*2+1,mid+1,r,ind,val);
            
            seg_tree[node]=max(seg_tree[node*2],seg_tree[node*2+1]);
        }

        ll query(int node, ll st,ll en,ll l,ll r){
            if(st>r || st>en || en<l)
                return 0;
            
            if(st>=l && en<=r)
                return seg_tree[node];
            
            int mid=(st+en)/2;
            return max(query(node*2,st,mid,l,r),query(node*2+1,mid+1,en,l,r));
        }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        ll n=nums.size();
        segTree inc_sub(n),dec_sub(n);
        vector<ll> dp_inc(n,0),dp_dec(n,0);

        map<ll,ll> hsh;
        for(auto e:nums)
            hsh[e]++;
        
        ll c=1;
        for(auto &it:hsh)
            it.second=c++;

        ll ans=0;
        for(ll i=0;i<n;i++){
            ll hsh_val=hsh[nums[i]];
            if(i-k>=0){
                inc_sub.update(1,1,n,hsh[nums[i-k]],dp_inc[i-k]);
                dec_sub.update(1,1,n,hsh[nums[i-k]],dp_dec[i-k]);
            }

            dp_inc[i]=max(0ll,dec_sub.query(1,1,n,1,hsh_val-1))+nums[i];
            dp_dec[i]=max(0ll,inc_sub.query(1,1,n,hsh_val+1,n))+nums[i];
            ans=max(ans,dp_inc[i]);
            ans=max(ans,dp_dec[i]);
        }

        return ans;

    }
};