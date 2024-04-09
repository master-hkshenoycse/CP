#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int v,int c,vector<vector<pair<int,int> > > &adj,vector<int> &component,vector<vector<int> > &zero_present){
        component[v]=c;
        
        for(auto to:adj[v]){
            int nx=to.first;
            int wt=to.second;
            
            for(int j=0;j<=20;j++){
                if((wt & (1<<j))==0){
                    zero_present[c][j]=1;
                }
            }
            
            if(component[nx]==-1){
                dfs(nx,c,adj,component,zero_present);
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
       vector<int> component(n+1,-1);
       vector<vector<int> > zero_present(n+5,vector<int> (21,0));
       vector<vector<pair<int,int> > > adj(n+1);
        
       for(auto e:edges){
           adj[e[0]].push_back({e[1],e[2]});
           adj[e[1]].push_back({e[0],e[2]});
       }
       
        
       int c=0;
        
       for(int i=0;i<n;i++){
           if(component[i]==-1){
               c++;
               dfs(i,c,adj,component,zero_present);
           }
       }
        
        vector<int> sol;
        
        for(auto q:query){
            int x=q[0];
            int y=q[1];
            
            if(component[x] != component[y]){
                sol.push_back(-1);
            }else{
                
                int ans=0;
                for(int i=0;i<=20;i++){
                    if(zero_present[component[x]][i]){
                        ans+=0;
                    }else{
                        ans+=(1<<i);
                    }
                }
                
                if(x==y){
                    ans=0;
                }
                sol.push_back(ans);
                
            }
                
        }
        
        return sol;
       
        
        
        
    }
};