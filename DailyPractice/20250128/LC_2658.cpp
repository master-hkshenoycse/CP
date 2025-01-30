#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vis[15][15];
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int sz=0;
    void dfs(int x,int y,int n,int m,vector<vector<int> >&grid){
        sz+=grid[x][y];
        vis[x][y]=1;
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and grid[nx][ny]>0){
                dfs(nx,ny,n,m,grid);
            }
        }
        
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 and vis[i][j]==0){
                    sz=0;
                    dfs(i,j,n,m,grid);
                    ans=max(ans,sz);
                }
            }
        }
        
        
        return ans;
    }
};