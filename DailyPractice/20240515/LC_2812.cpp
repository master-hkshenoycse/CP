#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dist_theifs[405][405];
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int vis[405][405];
    
    void dfs(int x,int y,int n,int lim){
        
        
       // cout<<x<<" "<<y<<" "<<n<<" "<<lim<<endl;
        if(dist_theifs[x][y]<lim){
            return ;
        }
        
        
        vis[x][y]=1;
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 and nx<n and ny>=0 and ny<n and vis[nx][ny]==0){
                dfs(nx,ny,n,lim);
            }
        }
        
        
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int lo=0,hi=800,ans=0;
        
        int n=grid.size();
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dist_theifs[i][j]=0;
                    q.push({i,j});
                }else{
                    dist_theifs[i][j]=1e9;
                }
            }
        }
        
        while(q.size()>0){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 and nx<n and ny>=0 and ny<n and dist_theifs[nx][ny]>dist_theifs[x][y]+1){
                    q.push({nx,ny});
                    dist_theifs[nx][ny]=dist_theifs[x][y]+1;
                }
            }
        }
        
        
        
        
        while(hi>=lo){
            int mid=(hi+lo)/2;
            memset(vis,0,sizeof(vis));
            
            dfs(0,0,n,mid);
            
            if(vis[n-1][n-1]){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        
        
        
        return ans;
    }
};