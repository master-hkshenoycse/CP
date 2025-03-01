#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> adj[200005];
        int bob_time[200005];
        int par[200005];
        int ans=INT_MIN;
        
        void dfs_par(int v,int p){
            par[v]=p;
            for(auto to:adj[v]){
                if(to==p)continue;
                dfs_par(to,v);
            }
        }
        
        void dfs(int v,int p,int h,int c,vector<int> &amt){
            
            if(h<bob_time[v]){
                c=c+amt[v];
            }else if(h==bob_time[v]){
                c=c+amt[v]/2;
            }
            
            if(v!=0 and adj[v].size()==1){
                ans=max(ans,c);
            }
            
            for(auto to:adj[v]){
                if(to==p)continue;
                dfs(to,v,h+1,c,amt);
            }
        }
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            
            int n=edges.size()+1;
            for(auto e:edges){
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            
            for(int i=0;i<n;i++){
                bob_time[i]=1e9;
            }
            dfs_par(0,-1);
            
            
            int tim=0,c=bob;
            while(c>=0){
                bob_time[c]=tim;
                tim++;
                c=par[c];
            }
            
            dfs(0,-1,0,0,amount);
            
            return ans;
        }
    };