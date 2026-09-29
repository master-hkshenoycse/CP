#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int memo[105][105][205];
    int dp[105][105][205];
    int isp(int x,int y,int bal,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        if(x==n-1 and y==m-1)
            return bal==0;

        if(memo[x][y][bal])
            return dp[x][y][bal];
        
        memo[x][y][bal]=1;
        int res=0;
        
        if(x+1<n){
            if(grid[x+1][y]=='(')
                res=max(res,isp(x+1,y,bal+1,grid));

            if(grid[x+1][y]==')' and bal>0)
                res=max(res,isp(x+1,y,bal-1,grid));            
        }
        
        if(y+1<m){
            if(grid[x][y+1]=='(')
                res=max(res,isp(x,y+1,bal+1,grid));
            
            if(grid[x][y+1]==')' and bal>0)
                res=max(res,isp(x,y+1,bal-1,grid));

        }
        
        return dp[x][y][bal]=res;
                
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        
        if(grid[0][0]==')')return 0;
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[n-1][m-1]=='(')return 0;
        
        if((n+m-1)%2)return 0;
        
        return isp(0,0,1,grid);
    }
};