#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod=1e9+7;
    int solve(int x,int y,int prev,vector<vector<int>>& grid, vector<vector<vector<int> > > &dp){
        if(x>=grid.size() || y>=grid[0].size())return 0;
        if(x==grid.size()-1 && y==grid[0].size()-1)return 1;
        if(dp[x][y][prev+1] != -1)return dp[x][y][prev+1];
        if(grid[x][y]==1){
            if(prev==0){
                return solve(x+1,y,1,grid,dp);
            }
            if(prev==1){
                return solve(x,y+1,0,grid,dp);
            }
        }
        return dp[x][y][prev+1]=(solve(x+1,y,1,grid,dp)+solve(x,y+1,0,grid,dp))%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int> > > dp(n,vector<vector<int> > (m,vector<int> (3,-1)));
        return solve(0,0,-1,grid,dp);
    }
};