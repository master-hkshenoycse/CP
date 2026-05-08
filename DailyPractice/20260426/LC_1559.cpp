#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int n,m;
    int vis[505][505];
    bool sol=0;
    vector<vector<char>> grid;
    bool chk(int x,int y){
        if(x>=0 && x<m && y>=0 && y<n)return 1;
        return 0;
    }
    int dx[5]={1,-1,0,0};
    int dy[5]={0,0,1,-1};
    void dfs(int x,int y,int px,int py){
        
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(!chk(nx,ny))continue;
                if(nx==px && ny==py)continue;
                if(grid[nx][ny]!=grid[x][y])continue;
                if(vis[nx][ny])sol=1;
                if(!vis[nx][ny])dfs(nx,ny,x,y);
            
        }
        
    }
    bool containsCycle(vector<vector<char>>& grid_c) {
        grid=grid_c;
        m=grid.size();
        n=grid[0].size();
        
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
                  if(vis[i][j])continue;
                  dfs(i,j,i,j);
                  if(sol){
                      return sol;
                  } 
            }
        }
        
        return sol;
    }
};