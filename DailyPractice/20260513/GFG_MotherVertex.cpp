#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
      vis[node]=true;
      
      for(int ch: adj[node]){
        if(!vis[ch]) dfs(ch, vis, adj);  
      }
      
      return;
    }
    
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool> vis(V, false);
      vector<vector<int>> adj(V);
      
      for(vector<int> &x: edges){
        adj[x[0]].push_back(x[1]);  
      }
      
      int cand=0;
      for(int i=0; i<V; i++){
        if(!vis[i]){
          cand=i;
          dfs(i, vis, adj);
        }  
      }
      
      fill(vis.begin(), vis.end(), false);
      
      dfs(cand, vis, adj);
      for(int i=0; i<V; i++){
        if(!vis[i]) return -1; 
      }
      
      return cand;
    }
};