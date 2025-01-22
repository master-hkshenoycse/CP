#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    bool chk(int x,int y){
        if(x>=0 and x<n and y>=0 and y<m)return 1;
        return 0;
    }
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        queue< pair<int,int> >q;
        n=isWater.size();
        m=isWater[0].size();
        
        vector< vector<int> > sol(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)sol[i][j]=INT_MAX;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    sol[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        
        while(q.size()){
            int x=q.front().first;
            int y=q.front().second;
        
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(chk(nx,ny) and sol[nx][ny]> sol[x][y]+1){
                    sol[nx][ny]=sol[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        
        
        return sol;
        
    }
};