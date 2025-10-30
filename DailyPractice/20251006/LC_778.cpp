#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int a[55][55];
    int vis[55][55];
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    int n;
    bool chk(int v){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                vis[i][j]=1e5;
            }
        }
        queue<pair<int,int> > q;
        
        
        if(a[1][1]<=v){
            vis[1][1]=0;
            q.push({1,1});    
        }
        
        
        while(q.size()){
           int x=q.front().first;
           int y=q.front().second;
           q.pop();
            
           for(int i=0;i<4;i++){
              int nx=x+dx[i];
              int ny=y+dy[i];
               
              if(nx>=1 and nx<=n and ny>=1 and ny<=n and a[nx][ny]<=v and vis[nx][ny]>vis[x][y]+1){
                  q.push({nx,ny});
                  vis[nx][ny]=vis[x][y]+1;
              } 
           }
        }
        
        return vis[n][n]<1e5;
    }
    int swimInWater(vector<vector<int>>& grid) {
        
        int lo=0;
        int hi=10000;
        int ans=10000;
        n=grid.size();
    
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=grid[i-1][j-1];
            }
        }
        
        while(hi>=lo){
            
            int m=(hi+lo)/2;
            
            if(chk(m)){
                hi=m-1;
                ans=min(ans,m);
            }else{
                lo=m+1;
            }
        }
        
        return ans;
    }
};