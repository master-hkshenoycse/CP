#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void dfs(int v,int p,vector<vector<ll> >&adj, vector<int> &cost, vector<ll> &max_cost){
        max_cost[v]=0;
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs(to,v,adj,cost,max_cost);
            max_cost[v]=max(max_cost[v],max_cost[to]);
        }

        max_cost[v]+=cost[v]*1ll;
    }

    void dfs_2(int v,int p,vector<int> &cost,vector<vector<ll> > &adj, vector<ll> &max_cost,ll curr, ll req, ll &ans){
        
        //cout<<v<<" "<<curr<<" "<<req<<" "<<max_cost[v]<<endl;
        if(req-max_cost[v] > curr ){
            ans++;
            curr+=req-max_cost[v]-curr;
        }
        
        curr+=cost[v]*1ll;
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs_2(to,v,cost,adj,max_cost,curr,req,ans);
        }
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<ll> > adj(n);
        vector<ll> max_cost(n,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ll ans=0;
        dfs(0,-1,adj,cost,max_cost);
        cout<<max_cost[0]<<endl;
        dfs_2(0,-1,cost,adj,max_cost,0,max_cost[0],ans);

        
        return ans;

    }
};