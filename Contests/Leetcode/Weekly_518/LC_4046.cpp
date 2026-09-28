#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int dp[76][76][76][5];

    int dfs(int x,int y,int rem,int prev,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        if(x==n-1 && y==m-1)
            return grid[x][y];
        
        if(dp[x][y][rem][prev]!=-1)
            return dp[x][y][rem][prev];
        
        int ret=1e9;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int ex=0;
            if(prev!=i)
                ex=1;
            if(rem-ex<0){
                continue;
            }
            if(nx>=0 && nx<n && ny>=0 && ny<m)
                ret=min(ret,grid[x][y]+dfs(nx,ny,rem-ex,i,grid));
        }
        return dp[x][y][rem][prev]=ret;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        memset(dp,-1,sizeof(dp));

        int ret=dfs(0,0,k+1,4,grid);
        if(ret == 1e9)
            ret=-1;
        return ret;
    }
};