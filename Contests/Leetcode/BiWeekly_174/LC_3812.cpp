#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int v,int p,vector<vector<pair<int,int> > > &adj,string &start,string &target,vector<int> &sol){
        
        for(auto to:adj[v]){
            if(to.first == p)
                continue;
            dfs(to.first,v,adj,start,target,sol);

            if(start[to.first] != target[to.first]){
                sol.push_back(to.second);
                start[to.first]=target[to.first];
                start[v]=char('0'+(1-(start[v]-'0')));
            }
        }
    }
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<vector<pair<int,int> > > adj(n);
        for(int i=0;i<n-1;i++){
            auto e=edges[i];
            adj[e[0]].push_back({e[1],i});
            adj[e[1]].push_back({e[0],i});
        }

        vector<int> sol;
        dfs(0,-1,adj,start,target,sol);
        sort(sol.begin(),sol.end());

        if(start != target)
            return {-1};
    
        return sol;

         
    }
};