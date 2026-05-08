#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int j,vector<vector<int> >&grid, int k, auto &dp){
        int n=grid.size(),m=grid[0].size();
        if(i==n || j==m) return INT_MIN;
        int cost=0,score=0;
        if(grid[i][j]==1)
            cost=1,score=1;
        
        if(grid[i][j]==2)
            cost=1,score=2;

        if(i==n-1 && j==m-1){
            if(cost<=k)return score;
            else return INT_MIN;
        }
    

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        
        
        int ret=INT_MIN;
        if(k>=cost){
            ret=max(ret,score+solve(i+1,j,grid,k-cost,dp));
            ret=max(ret,score+solve(i,j+1,grid,k-cost,dp));
        }

        return dp[i][j][k]=ret;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(m,vector<int> (k+1,-1)));
        int ans=solve(0,0,grid,k,dp);
        if(ans<0)
            ans=-1;

        return ans;
    }
};