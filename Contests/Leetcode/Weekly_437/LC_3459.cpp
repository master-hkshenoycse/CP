#include<bits/stdc++.h>
using namespace std;

int dp[501][501][4][2];

class Solution {
public:
    int dx[4]={-1,1,1,-1};
    int dy[4]={1,1,-1,-1};
    
    int solve(int i,int j,int req,int dir,int ch,vector<vector<int> > &grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] != req){
            return -1;
        }
        
        if(dp[i][j][dir][ch] != -1){
            return dp[i][j][dir][ch];
        }
        
        int n_dir=dir;
        int ni=i+dx[n_dir];
        int nj=j+dy[n_dir];
        int n_req;
        if(req==2){
            n_req=0;
        }else{
            n_req=2;
        }
        
        int ret=solve(ni,nj,n_req,n_dir,ch,grid)+1;
        if(ch==0){
            n_dir=(dir+1)%4;
            int ni=i+dx[n_dir];
            int nj=j+dy[n_dir];
            ret=max(ret,1+solve(ni,nj,n_req,n_dir,1,grid)+1);
        }

        return dp[i][j][dir][ch]=ret;
        
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    dp[i][j][k][0]=-1;
                    dp[i][j][k][1]=-1;

                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,1);
                    for(int k=0;k<4;k++){
                        if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m){
                           ans=max(ans,solve(i+dx[k],j+dy[k],2,k,0,grid)+1); 
                           cout<<i<<" "<<j<<" "<<solve(i+dx[k],j+dy[k],2,k,0,grid)<<endl;
                        }
                    }

                }
            }
        }
        
        return ans;
    }
};