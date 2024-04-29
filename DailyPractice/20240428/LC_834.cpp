
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> adj[200005];
    int sz[200005],sol[200005];

    void dfs(int v,int p){
        sz[v]=1;
        for(auto to:adj[v]){
            if(to==p)continue;
            dfs(to,v);
            sol[v]+=(sol[to]+sz[to]);
            sz[v]+=sz[to];
        }
    }

    void dfs2(int v,int p,int n){
        
        if(p>=0){
           sol[v]=sol[p];
           sol[v]-=sz[v];
           sol[v]+=(n-sz[v]);
        }

        for(auto to:adj[v]){
            if(to==p)continue;
            dfs2(to,v,n);
        }
    }

     

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++){
            adj[i].clear();
        }

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0,-1);
        dfs2(0,-1,n);
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(sol[i]);
        }
        return ans;
        
    }
};