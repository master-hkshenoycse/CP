#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dfs(ll v,ll p,ll par_rem,vector<vector<pair<ll,ll> > >&adj,vector<vector<ll> > &dp,ll k){
        vector<ll> res_with_child;
        ll ret=0;
        if(dp[v][par_rem] != -1e18){
            return dp[v][par_rem];
        }

        for(auto to:adj[v]){
           if(to.first==p){
             continue;
           }
           ll res_0=dfs(to.first,v,0,adj,dp,k);
           ll res_1=dfs(to.first,v,1,adj,dp,k)+to.second;
           ret+=res_0;
           res_with_child.push_back(res_1-res_0);
        }

        ll child_allowed=k-par_rem;
        sort(res_with_child.begin(),res_with_child.end());
        reverse(res_with_child.begin(),res_with_child.end());
        for(ll i=0;i<res_with_child.size();i++){
            if(i+1>child_allowed){
                break;
            }
            if(res_with_child[i]<0){
                break;
            }
            ret=ret+res_with_child[i];
        }
       
        return dp[v][par_rem]=ret;

    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        ll n=edges.size()+1;
        vector<vector<pair<ll,ll> > > adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        vector<vector<ll> > dp(n,vector<ll> (2,-1e18));
        return dfs(0,-1,0,adj,dp,k);
       

    }
};