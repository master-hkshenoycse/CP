#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_height(ll ind,vector<vector<ll> >&adj){
        ll h=0;
        for(auto nx:adj[ind])
            h=max(h,1+get_height(nx,adj));
        return h;
    }

    void get_weight(ll ind, ll d,ll h, vector<vector<ll> >&adj,vector<int> &nums,ll &ans){
        ans=ans+nums[ind]*1ll*(h-d+1ll);
        for(auto nx:adj[ind])
            get_weight(nx,d+1,h,adj,nums,ans);
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        ll n=parent.size();
        vector<vector<ll> > adj(n);    
        for(ll i=1;i<n;i++)
            adj[parent[i]].push_back(i);
        ll h=get_height(0,adj);
        ll ret=0;
        get_weight(0,0,h,adj,nums,ret);
        return ret;
    }
};