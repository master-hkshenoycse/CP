#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> adj[55];
        int vis[55];
        int cnt_edges=0,cnt_verts=0;
        
        void dfs(int v){
            vis[v]=1;
            cnt_verts++;
            for(auto to:adj[v]){
                cnt_edges++;
                if(vis[to]==0){
                    dfs(to);
                }
            }
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            for(int i=0;i<n;i++){
                vis[i]=0;
                adj[i].clear();
                adj[i].clear();
            }
            
            for(auto e:edges){
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            
            
            int ans=0;
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    cnt_edges=0;
                    cnt_verts=0;
                    
                    dfs(i);
                    
                    if(cnt_verts*(cnt_verts-1)==cnt_edges){
                        ans++;
                    }
                }
            }
            
            return ans;
        }
        
    };