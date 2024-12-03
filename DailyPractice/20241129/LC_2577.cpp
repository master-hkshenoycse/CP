#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        vector<vector<int> > dp(n,vector<int> (m,1e9));
        dp[0][0]=0;
        set<vector<int> > s;
        s.insert({0,0,0});

        int is_adj=0;
        for(int i=0;i<4;i++){
            int x=0+dx[i];
            int y=0+dy[i];
            if(x>=0 and y>=0 and x<n and y<m and grid[x][y]<=1){
                is_adj=1;
            }
        }

        cout<<is_adj<<endl;

        while(s.size()>0){
            auto it=*s.begin();
            s.erase(it);

            int x=it[1];
            int y=it[2];

            

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<m){
                    int d=dp[x][y]+1;
                    if(grid[nx][ny]>d and is_adj==0){
                        continue;
                    }
                    if(grid[nx][ny]>d){
                        int diff=grid[nx][ny]-d;
                        d=grid[nx][ny]+(diff%2);
                    }
                    //cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<" "<<d<<" "<<grid[nx][ny]<<endl;
                    if(dp[nx][ny]>d){
                        dp[nx][ny]=d;
                        s.insert({dp[nx][ny],nx,ny});
                    }
                }
            }
        }

        int ret=dp[n-1][m-1];
        if(ret==1e9){
            ret=-1;
        }
        return ret;
    }
};