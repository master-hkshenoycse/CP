#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int v,vector<vector<int> > &adj,vector<int> &vis){
        vis[v]=1;
        for(auto to:adj[v]){
            if(vis[to]==0){
                dfs(to,adj,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int> > adj(n),rev_adj(n);
        vector<int> vis(n,0);
        for(auto i:invocations){
            adj[i[0]].push_back(i[1]);
            rev_adj[i[1]].push_back(i[0]);
        }

        dfs(k,adj,vis);

        int rem=1;
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                for(auto nx:rev_adj[i]){
                    if(vis[nx]==0){
                        rem=0;
                    }
                }
            }
        }

        vector<int> sol;
        for(int i=0;i<n;i++){
            if(rem and vis[i]==1){
                continue;
            }
            sol.push_back(i);
        }

        return sol;
        
    }
};