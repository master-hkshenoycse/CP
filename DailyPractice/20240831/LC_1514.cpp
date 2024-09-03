#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> dp(n,0.0000);
        vector<pair<int,double> > adj[n];

        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        dp[start]=1.000;
        priority_queue<pair<double,int> > s;
        s.push({dp[start],start});

        while(s.size()>0){
            int v=s.top().second;
            s.pop();

            for(auto to:adj[v]){
                int nx=to.first;
                double p=to.second;

                if(dp[nx]<dp[v]*p){
                    dp[nx]=dp[v]*p;
                    s.push({dp[nx],nx});
                }
            }
        }

        return dp[end];
    }
};