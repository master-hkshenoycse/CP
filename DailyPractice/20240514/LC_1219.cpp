#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int get_gold(int x,int y,vector<vector<int> >&grid,vector<vector<int> >&vis){
        int n=grid.size(),m=grid[0].size();
        vis[x][y]=1;
        int ret=grid[x][y];

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and grid[nx][ny]>0){
                ret=max(ret,grid[x][y]+get_gold(nx,ny,grid,vis));
            }
        }

        vis[x][y]=0;
        return ret;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    ans=max(ans,get_gold(i,j,grid,vis));
                }
            }
        }

        return ans;
    }
};