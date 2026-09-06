#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public: 
    ll dfs(ll v,ll p,vector<vector<ll> >&adj, vector<int> &baseTime){
        
        ll earliest=1e18,latest=-1e18;
        for(auto to:adj[v]){
            if(to==p)
                continue;
            ll fin_time=dfs(to,v,adj,baseTime);
            earliest=min(earliest,fin_time);
            latest=max(latest,fin_time);
        }

        if(earliest==1e18)
            return baseTime[v];
        
        return 2*latest-earliest+baseTime[v];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        
        vector<vector<ll> >adj(n);
        for(auto e:edges)
            adj[e[0]].push_back(e[1]),adj[e[1]].push_back(e[0]);
        
        return dfs(0,-1,adj,baseTime);
    }
};