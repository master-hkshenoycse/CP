#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_distance(vector<vector<int> >&adj,int n){
        vector<int> dp(n,INT_MAX);
        queue<int> q;
        dp[0]=0;
        q.push(0);

        while(q.size()>0){
            int v=q.front();
            q.pop();

            for(auto to:adj[v]){
                if(dp[to]>dp[v]+1){
                    dp[to]=dp[v]+1;
                    q.push(to);
                }
            }
        }

        return dp[n-1];

    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int> > adj(n);
        for(int i=0;i+1<n;i++){
            adj[i].push_back(i+1);
        }

        vector<int> sol;
        for(auto q:queries){
            adj[q[0]].push_back(q[1]);
            sol.push_back(get_distance(adj,n));
        }

        return sol;

    }
};