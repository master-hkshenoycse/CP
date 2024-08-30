#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int a[505][505];
    int b[505][505];
    int comp_a[505][505];
    int comp_b[505][505];
    
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    int c=1;
    int n,m;
    bool chk(int x,int y,int ind){
        int f= (x>=1 and x<=n and y>=1 and y<=m) ;
        if(f==0)return 0;
        
        if(ind==1){
            return comp_a[x][y]==0 and a[x][y]==1;
        }
        return comp_b[x][y]==0 and b[x][y]==1;
        
    }
    void dfs(int x,int y,int ind){
        
        if(ind==1){
            comp_a[x][y]=c;
        }else{
            comp_b[x][y]=c;
        }
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(chk(nx,ny,ind)){
                dfs(nx,ny,ind);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=grid1[i-1][j-1];
                b[i][j]=grid2[i-1][j-1];
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(comp_a[i][j]==0 and a[i][j]==1){
                    dfs(i,j,1);
                    c++;
                }
            }
        }
        
        c=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(comp_b[i][j]==0 and b[i][j]==1){
                    dfs(i,j,2);
                    c++;
                }
            }
        }
        
        
        
        map<int,set<int> > help;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(comp_b[i][j]>0)help[comp_b[i][j]].insert(comp_a[i][j]);
            }
        }
        
        int ans=0;
        
        
        for(auto it:help){
            if(it.second.size()==1 and *((it.second).begin())>0) ans++; 
        }
        
        return ans;
        
        
        
        
    }
};