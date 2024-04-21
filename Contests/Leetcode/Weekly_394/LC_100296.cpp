#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<ll> get_dijstra(ll source,vector<vector< pair<ll,ll > > > &adj){
        ll n=adj.size();
        vector<ll> dp(n,1e15);
        
        priority_queue<pair<ll,ll> > pq;
        dp[source]=0;
        pq.push({0,source});
        
        while(pq.size()>0){
            ll v=pq.top().second;
            pq.pop();
            
            for(auto to:adj[v]){
                ll nx=to.first;
                ll wt=to.second;
                
                if(dp[nx]>dp[v]+wt){
                    dp[nx]=dp[v]+wt;
                    pq.push({-dp[nx],nx});
                }
            }
                
        }
        
        return dp;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector< pair<ll,ll > > > adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        vector<ll> dis_from_s=get_dijstra(0,adj);
        vector<ll> dis_from_t=get_dijstra(n-1,adj);
        ll req=dis_from_s[n-1];
        
        vector<bool> sol;
        
        for(auto e:edges){
            ll x=e[0];
            ll y=e[1];
            ll wt=e[2];
            bool curr=false;
            if(dis_from_s[x]+dis_from_t[y]+wt==req){
                curr=true;
            }
            
            if(dis_from_s[y]+dis_from_t[x]+wt==req){
                curr=true;
            }
            
            sol.push_back(curr);
        }
        
        
        return sol;
    }
};