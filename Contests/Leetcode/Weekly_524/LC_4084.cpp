#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        int x=0,y=0;


        while(1){
            vis[x][y]=1;
            int nx=x,ny=y;
            if(grid[x][y]=='L'){
                ny--;
            }else if(grid[x][y]=='R'){
                ny++;
            }else if(grid[x][y]=='U'){
                nx--;
            }else if(grid[x][y]=='D'){
                nx++;
            }   

            if(nx<0 || ny<0 || nx==n || ny==m || vis[nx][ny]==1)
                return {x,y};
            x=nx;
            y=ny;
            
        }   

        return {-1,-1};
    }
};