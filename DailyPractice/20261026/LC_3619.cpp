#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(int x,int y,vector<vector<int> >&grid,vector<vector<int> > &vis,int &sum,int k){
        sum=(sum+grid[x][y])%k;
        vis[x][y]=1;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && vis[nx][ny]==0 && grid[nx][ny]>0)
                dfs(nx,ny,grid,vis,sum,k);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ret=0,n=grid.size(),m=grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && vis[i][j]==0){
                    int sum=0;
                    dfs(i,j,grid,vis,sum,k);
                    if(sum==0)
                        ret++;
                }
            }
        }

        return ret;
    }
};