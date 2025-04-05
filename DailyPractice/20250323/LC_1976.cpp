#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dp[205];
    ll mod=1e9+7;
    ll dist[205];
    
    vector<pair<ll,ll> > adj[205];
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        for(auto e:roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        for(ll i=0;i<n;i++){
            dp[i]=0;
            dist[i]=1e15;
        }
        
        priority_queue<pair<ll,ll> > s;
        dp[0]=1;
        dist[0]=0;
        
        s.push({0,0});
        
        while(s.size()){
            
            ll v=(s.top()).second;
            ll c_d=-1*(s.top()).first;
            s.pop();
            
            if(c_d > dist[v]){
                continue;
            }
            for(auto nx:adj[v]){
                ll to=nx.first;
                ll d=nx.second;
                
                if(dist[to]>dist[v]+d){
                    dist[to]=dist[v]+d;
                    s.push({-dist[to],to});
                    dp[to]=dp[v];
                     
                }else if(dist[to]==dist[v]+d){
                    dp[to]=(dp[to]+dp[v])%mod;
                }
                

            }
        }
        
        return (int)dp[n-1];
        
        
        
        
    }
};