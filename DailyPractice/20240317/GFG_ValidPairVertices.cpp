#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Binary lifting based solution

class Solution {
  public:
    void dfs(ll v,ll p,vector<vector<pair<ll,ll>  > >&adj,vector<vector<ll> >&dist_par,vector<vector<ll> >&par,vector<int> &val,ll &ans){
        
        for(ll i=1;i<=20;i++){
            if(par[v][i-1] != -1){
                par[v][i]=par[par[v][i-1]][i-1];
                dist_par[v][i]=dist_par[v][i-1]+dist_par[par[v][i-1]][i-1];
            }
        }
        
        ll req=val[v-1];
        ll curr=v;
        
        for(ll i=20;i>=0;i--){
            
            if(par[curr][i] != -1 and req>=dist_par[curr][i]){
                ans=ans+(1ll<<i);
                req-=dist_par[curr][i];
                curr=par[curr][i];
            }
                
        }
        
        for(auto to:adj[v]){
            if(to.first == p){
                continue;
            }
            
            par[to.first][0]=v;
            dist_par[to.first][0]=to.second;
            
            dfs(to.first,v,adj,dist_par,par,val,ans);
        }
    }
    long long validPairs(int n, vector<int>&val,vector<vector<int>>&edges) {
        // code here
        vector<vector<pair<ll,ll>  > > adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        ll ans=0;
        vector<vector<ll> > dist_par(n+1,vector<ll>(21,0));
        vector<vector<ll> > par(n+1,vector<ll>(21,-1));
        dfs(1,-1,adj,dist_par,par,val,ans);
        
        return ans;
        
    }
};