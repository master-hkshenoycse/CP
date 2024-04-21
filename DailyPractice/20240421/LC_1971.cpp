#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> adj[200005];
    int vis[200005];

    void dfs(int v){
        vis[v]=1;
        for(auto to:adj[v]){
            if(vis[to]==0){
                dfs(to);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0;i<n;i++){
            adj[i].clear();
        }

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(source);
        return vis[destination]==1;
    }
};