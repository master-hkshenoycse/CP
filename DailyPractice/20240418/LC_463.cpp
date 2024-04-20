#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dx={-1,1,0,0},dy={0,0,-1,1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    
                    if(nx>=0 and nx<n and ny>=0 and ny<m){
                        ans+=(grid[nx][ny]==0);
                    }else{
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};