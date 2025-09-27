#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int v, vector<vector<pair<int,int> > > &adj, vector<int> &vis,int wt){
        vis[v]=1;
        for(auto to:adj[v]){
            if(vis[to.first]==0 && to.second<=wt){
                dfs(to.first,adj,vis,wt);
            }
        }
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int lo=0,hi=1e6,ret=1e6;
        vector<int> vis(n,0);
        vector<vector<pair<int,int> > > adj(n);
        
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        while(hi>=lo){
            int mid=(hi+lo)/2;  

            int comp=0;

            for(int i=0;i<n;i++){
                vis[i]=0;
            }
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    comp++;
                    dfs(i,adj,vis,mid);
                }
            }

            if(comp<=k){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ret;
    }
};