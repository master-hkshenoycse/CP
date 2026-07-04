#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vis_1[100005],vis_n[100005];
    vector<int> adj[100005];
    void dfs(int v,int *vis){
        vis[v]=1;
        for(auto to:adj[v]){
            if(vis[to])continue;
            dfs(to,vis);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        
        for(auto r:roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
  
        dfs(1,vis_1);
        dfs(n,vis_n);
        
        int ans=INT_MAX;
        for(auto r:roads){
            if(vis_1[r[0]] and vis_n[r[1]]){
                ans=min(ans,r[2]);
            }
            
            if(vis_1[r[1]] and vis_n[r[0]]){
                ans=min(ans,r[2]);
            }
            
        }
        return ans;
        
    }
};