#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        set<pair<int,int> > pq;
        vector<int> dp(n,INT_MAX);
        vector<vector<pair<int,int> > > adj(n);

        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],2*e[2]});
        }
        
        dp[0]=0;
        pq.insert({0,0});

        while(pq.size()>0){
            int u=(*pq.begin()).second;
            int d=(*pq.begin()).first;
            pq.erase(pq.begin());

            if(dp[u] > d){
                continue;
            }

            for(auto to:adj[u]){
                int nx=to.first;
                int wt=to.second;
                if(dp[nx]>dp[u]+wt){
                    dp[nx]=dp[u]+wt;
                    pq.insert({dp[nx],nx});
                }
            }
        }

        if(dp[n-1]==INT_MAX){
            dp[n-1]=-1;
        }

        return dp[n-1];
        
    }
};