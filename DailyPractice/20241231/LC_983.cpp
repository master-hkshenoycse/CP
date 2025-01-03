#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int c1=0;
    int c2=0;
    int c3=0;
    int dp[506];
    int memo[506];
    int vis[506];
    int solve(int d){
        if(d>365){
            return 0;
        }
        if(memo[d])return dp[d];
        memo[d]=1;
        int ans=1e6;
        
        if(vis[d]==0){
            return dp[d]=solve(d+1);
        }
        ans=min(ans,c1+solve(d+1));
        ans=min(ans,c2+solve(d+7));
        ans=min(ans,c3+solve(d+30));
        return dp[d]=ans;
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        c1=costs[0];
        c2=costs[1];
        c3=costs[2];
        for(int i=1;i<=365;i++)vis[i]=0;
        int n=days.size();
        for(int i=0;i<n;i++)vis[days[i]]++;
    
        return solve(days[0]);
    }
};