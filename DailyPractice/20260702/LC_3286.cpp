#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > dp(n,vector<int> (m,1e9));

        set<vector<int> > s;
        dp[0][0]=grid[0][0];
        s.insert({grid[0][0],0,0});

        while(s.size()>0){
            int x=(*s.begin())[1];
            int y=(*s.begin())[2];

            s.erase(s.begin());

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<n  and ny<m and dp[nx][ny]>dp[x][y]+grid[nx][ny]){
                    dp[nx][ny]=dp[x][y]+grid[nx][ny];
                    s.insert({dp[nx][ny],nx,ny});
                }
            }

        }


        return dp[n-1][m-1]<=health-1;        
    }
};