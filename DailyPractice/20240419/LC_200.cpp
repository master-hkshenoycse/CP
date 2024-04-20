#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(int x,int y,vector<vector<char> > &grid,vector<vector<int> > &vis){
        int n=grid.size(),m=grid[0].size();
        vis[x][y]=1;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and grid[nx][ny]=='1'){
                dfs(nx,ny,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid,vis);
                }
                
            }
        }

        return ans;

    }
};