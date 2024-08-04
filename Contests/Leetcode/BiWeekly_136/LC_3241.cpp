#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int v,int p,vector<vector<int> >&adj,vector<int> &max_time,vector<int> &first_time,int curr_time){
        max_time[v]=max(max_time[v],curr_time);
        first_time[v]=curr_time;
        
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            
            if(to%2){
                dfs(to,v,adj,max_time,first_time,curr_time+1);
            }else{
                dfs(to,v,adj,max_time,first_time,curr_time+2);
            }
            
            
            max_time[v]=max(max_time[v],max_time[to]);
        }
        

        
    }
    
    void dfs2(int v,int p,vector<vector<int> >&adj,vector<int> &max_time,vector<int> &first_time,vector<int> &sol,int offset){
        //cout<<v<<" "<<offset<<endl;
        sol[v]=max(offset,max_time[v]-first_time[v]);
        
        vector<int> pref,suff;
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            pref.push_back(max_time[to]-first_time[v]);
            suff.push_back(max_time[to]-first_time[v]);
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
            
            int nx_offset=offset;
            
            if(c-1>=0){
                nx_offset=max(nx_offset,pref[c-1]);
            }
            
            if(c+1<sz){
                nx_offset=max(nx_offset,suff[c+1]);
            }
            
            if(v%2){
                nx_offset=nx_offset+1;
            }else{
                nx_offset=nx_offset+2;
            }
            
            dfs2(to,v,adj,max_time,first_time,sol,nx_offset);
            c++;
            
            
        }
    }
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        
        vector<vector<int> > adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> max_time(n+1,0);
        vector<int> first_time(n+1,0);
        
        dfs(0,-1,adj,max_time,first_time,0);
        
        vector<int> sol(n);
        
        dfs2(0,-1,adj,max_time,first_time,sol,0);
        
        
        return sol;
    }
};