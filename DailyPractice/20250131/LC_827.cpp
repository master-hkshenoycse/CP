#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int vis[505][505];
    int comp[505*505];
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    void dfs(int x,int y,int c,vector< vector<int> > &grid){
        vis[x][y]=c;
        comp[c]++;
       
        
        for(int i=0;i<4;i++){
            
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==1 and vis[nx][ny]==0){
                dfs(nx,ny,c,grid);
            }
        }
        
    
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        memset(vis,0,sizeof(vis));
        int c=0,ans=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1 and vis[i][j]==0){
                    c++;
                    dfs(i,j,c,grid);
                    ans=max(ans,comp[c]+1);
                }
           }
        }
        
        
        
        
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                
                if(grid[i][j]==0){
                    set<int> y;
                    for(int k=0;k<4;k++){
                        
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        
                        if(nx>=0 and nx<n and ny>=0 and ny<n and vis[nx][ny]>0){
                            y.insert(vis[nx][ny]);
                        }
                   }
                   
                   int s=0;
                   for(auto e:y){
                       s+=comp[e];
                   }
                    ans=max(ans,s+1);
                    
                }
                
                
            }
        }
        
        if(ans>n*n) ans=n*n;
        
        
        return ans;
        
    }
};