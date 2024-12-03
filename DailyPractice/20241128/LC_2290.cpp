#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
       int n=grid.size(),m=grid[0].size();
       vector<vector<int> > dp(n,vector<int> (m,INT_MAX)); 
       int dx[4]={-1,1,0,0};
       int dy[4]={0,0,-1,1};
        
       set<vector<int> >s;
       dp[0][0]=0;
       s.insert({0,0,0});
        
       while(s.size()>0){
           int x=(*s.begin())[1];
           int y=(*s.begin())[2];
           s.erase(s.begin());
           for(int i=0;i<4;i++){
               int nx=x+dx[i];
               int ny=y+dy[i];
               if(nx>=0 and nx<n and ny>=0 and ny<m and dp[nx][ny]>dp[x][y]+(grid[nx][ny]==1)){
                   dp[nx][ny]=dp[x][y]+(grid[nx][ny]==1);
                   s.insert({dp[nx][ny],nx,ny});
               }
           }
       }
        
        return dp[n-1][m-1];
    }
};