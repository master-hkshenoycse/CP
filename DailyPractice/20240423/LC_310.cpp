#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> adj[20005];
    int depth[20005],dp[200005];
    
    void dfs1(int v,int p){
        int ma=0;
        for(auto to:adj[v]){
            if(to==p)continue;
            dfs1(to,v);
            ma=max(ma,depth[to]);
        }
        depth[v]=ma+1;
    }
    
    void dfs2(int v,int p,int ph){
        vector<int> pref,suff;
        
        dp[v]=max(depth[v]-1,ph);
        cout<<v<<" "<<depth[v]<<" "<<ph<<endl;
        
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            pref.push_back(depth[to]);
            suff.push_back(depth[to]);
        }
        
        int sz=pref.size();
        for(int i=1;i<sz;i++){
            pref[i]=max(pref[i],pref[i-1]);
        }
        
        for(int i=sz-2;i>=0;i--){
            suff[i]=max(suff[i],suff[i+1]);
        }
        
        int c=0;
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            
            
                      
            int ma=ph+1;
            if(c-1>=0)ma=max(ma,pref[c-1]+1);
            if(c+1<sz)ma=max(ma,suff[c+1]+1);
            
            dfs2(to,v,ma);
                
            c++;
            
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        for(auto ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        
        dfs1(1,-1);
        dfs2(1,-1,0);
        
        int mi=1e9;
        for(int i=0;i<n;i++){
            mi=min(mi,dp[i]);
        }
        
       // cout<<mi<<endl;
        vector<int> sol;
        for(int i=0;i<n;i++){
            if(mi==dp[i]){
                sol.push_back(i);
            }
        }
        
        return sol;
    }
};