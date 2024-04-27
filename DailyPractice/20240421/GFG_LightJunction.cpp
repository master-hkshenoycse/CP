#include<bits/stdc++.h>
using namespace std;
#define ll long long

//https://practice.geeksforgeeks.org/contest/job-a-thon-32-hiring-challenge/problems
//Create DAG from acyclic graph
class Solution
{
    public:
    void dfs1(ll v,vector<vector<ll> > &adj,vector<ll> &vis,vector<ll> &dfs_order){
        vis[v]=1;
        
        for(auto to:adj[v]){
            if(vis[to]==0){
                dfs1(to,adj,vis,dfs_order);
            }
        }
        
        dfs_order.push_back(v);
    }
    
    void dfs2(ll v,vector<vector<ll> >&adj,vector<ll> &vis,vector<int> &cost,ll &val){
        val=min(val,cost[v-1]*1ll);
        vis[v]=1;
        for(auto to:adj[v]){
            if(vis[to]==0){
                dfs2(to,adj,vis,cost,val);
            }
        }
        
    }
    long long int minCost(int N,int M,vector<vector<int>> Edges,vector<int> Cost)
    {
        // code here!
        vector<vector<ll> > adj(N+1);
        vector<vector<ll> > rev_adj(N+1);
        
        for(auto e:Edges){
            adj[e[0]].push_back(e[1]);
            rev_adj[e[1]].push_back(e[0]);
        }
        vector<ll> dfs_order;
        vector<ll> vis(N+1,0);
        for(int i=1;i<=N;i++){
            if(vis[i]==0){
                dfs1(i,adj,vis,dfs_order);
            }
        }
        for(int i=1;i<=N;i++){
            vis[i]=0;
        }
        
        ll ans=0;
        while(dfs_order.size()>0){
            ll v=dfs_order.back();
            dfs_order.pop_back();
            
            if(vis[v]){
                continue;        
            }
            ll val=1e6;
            dfs2(v,rev_adj,vis,Cost,val);
            ans=ans+val;
            
       }
       return ans;
    }
};#define ll long long
class Solution
{
    public:
    void dfs1(ll v,vector<vector<ll> > &adj,vector<ll> &vis,vector<ll> &dfs_order){
        vis[v]=1;
        
        for(auto to:adj[v]){
            if(vis[to]==0){
                dfs1(to,adj,vis,dfs_order);
            }
        }
        
        dfs_order.push_back(v);
    }
    
    void dfs2(ll v,vector<vector<ll> >&adj,vector<ll> &vis,vector<int> &cost,ll &val){
        val=min(val,cost[v-1]*1ll);
        vis[v]=1;
        for(auto to:adj[v]){
            if(vis[to]==0){
                dfs2(to,adj,vis,cost,val);
            }
        }
        
    }
    long long int minCost(int N,int M,vector<vector<int>> Edges,vector<int> Cost)
    {
        // code here!
        vector<vector<ll> > adj(N+1);
        vector<vector<ll> > rev_adj(N+1);
        
        for(auto e:Edges){
            adj[e[0]].push_back(e[1]);
            rev_adj[e[1]].push_back(e[0]);
        }
        vector<ll> dfs_order;
        vector<ll> vis(N+1,0);
        for(int i=1;i<=N;i++){
            if(vis[i]==0){
                dfs1(i,adj,vis,dfs_order);
            }
        }
        for(int i=1;i<=N;i++){
            vis[i]=0;
        }
        
        ll ans=0;
        while(dfs_order.size()>0){
            ll v=dfs_order.back();
            dfs_order.pop_back();
            
            if(vis[v]){
                continue;        
            }
            ll val=1e6;
            dfs2(v,rev_adj,vis,Cost,val);
            ans=ans+val;
            
       }
       return ans;
    }
};