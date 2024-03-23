#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    int dfs(int v,int p,vector<vector<pair<int,int> > > &adj,vector<int> &mark,vector<int> &sol,int d,int s){
        
        if(d==0){
            mark[v]=1;
        }
        
        vector<int> c;
        int tot=0;
        for(auto to:adj[v]){
            if(to.first==p){
                continue;
            }
            int c_0=dfs(to.first,v,adj,mark,sol,(d+to.second)%s,s);
            c.push_back(c_0);
            tot+=c_0;
        }
        
        
        if(p==-1){
            
            int sz=c.size();
            for(int i=0;i<sz;i++){
                sol[v]+=(tot-c[i])*c[i];
            }
            
            sol[v]/=2;
            
        }
        
        tot+=mark[v];
        
        return tot;
        
        
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n=edges.size()+1;
        vector<int> sol(n,0),mark(n,0);
        vector<vector<pair<int,int> > > adj(n);
        
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mark[j]=0;
            }
            
            dfs(i,-1,adj,mark,sol,0,signalSpeed);
        }
        
        return sol;
        
    }
};