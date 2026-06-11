#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res * a)%mod;
            }
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    int dfs(int v,int p,vector<vector<ll> > &adj){
        int ret =0; 
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            ret=max(ret,1+dfs(to,v,adj));
        }
        return ret;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        ll n=edges.size()+1;
        
        vector<vector<ll> > adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int max_depth  = dfs(1,-1,adj);
        return modpow(2,max_depth-1);
    }
};