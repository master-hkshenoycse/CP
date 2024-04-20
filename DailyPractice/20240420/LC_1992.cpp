#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    vector<vector<int> > vis;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(int x,int y,int c,vector<vector<int> >&land){
        vis[x][y]=c;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and land[nx][ny]==1){
                dfs(nx,ny,c,land);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        vis.resize(n,vector<int>(m,0));
        
        int c=0;
        vector<vector<int> > sol;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 and vis[i][j]==0){
                    c++;
                    sol.push_back({INT_MAX,INT_MAX,INT_MIN,INT_MIN});
                    dfs(i,j,c,land);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]){
                    int c=vis[i][j]-1;
                    sol[c][0]=min(sol[c][0],i);
                    sol[c][1]=min(sol[c][1],j);
                    sol[c][2]=max(sol[c][2],i);
                    sol[c][3]=max(sol[c][3],j);
                }
            }
        }
        
        
        return sol;
        
        
        
        
    }
};