#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int x,int y,int rem,vector<vector<vector<int> > > &dp,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        if(x==n-1 and y==m-1){
            if(rem>0){
                return max(0,grid[x][y]);
            }
            return grid[x][y];
        }

        if(dp[x][y][rem] != INT_MIN){
            return dp[x][y][rem];
        }

        int ret=INT_MIN;
        
        if(x+1<n){
            ret=max(ret,grid[x][y]+solve(x+1,y,rem,dp,grid));
            if(rem>0){
                ret=max(ret,max(0,grid[x][y])+solve(x+1,y,rem-1,dp,grid));
            }
        }

        if(y+1<m){
            ret=max(ret,grid[x][y]+solve(x,y+1,rem,dp,grid));
            if(rem>0){
                ret=max(ret,max(0,grid[x][y])+solve(x,y+1,rem-1,dp,grid));
            }
        }


        return dp[x][y][rem]=ret;


    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size(),m=coins[0].size();
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(m,vector<int> (3,INT_MIN)));

        return solve(0,0,2,dp,coins);


    }
};