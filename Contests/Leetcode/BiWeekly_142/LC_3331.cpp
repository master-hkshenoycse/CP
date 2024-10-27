#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int v,int p,vector<vector<int> > &ls,vector<vector<int> >&adj,vector<int> &par,string &s){
        if(ls[s[v]-'a'].size()>0 ){
            par[v]=ls[s[v]-'a'].back();
        }
        ls[s[v]-'a'].push_back(v);

        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs(to,v,ls,adj,par,s);
        }

        ls[s[v]-'a'].pop_back();
    }

    void dfs2(int v,int p,vector<vector<int> >&adj,vector<int> &sol){
        sol[v]++;
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs2(to,v,adj,sol);
            sol[v]+=sol[to];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int> > adj(n),ls(26);


        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        dfs(0,-1,ls,adj,parent,s);
        for(int i=0;i<n;i++){
            adj[i].clear();
        }

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        vector<int> sol(n,0);
        dfs2(0,-1,adj,sol);
        return sol;
    }
};