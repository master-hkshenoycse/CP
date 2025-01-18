#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(m,vector<int> (4,1e9)));
        set<vector<int> > distra_set;

        for(int i=0;i<4;i++){
            if(grid[0][0]==i+1){
                dp[0][0][i]=0;
                distra_set.insert({0,0,0,i});
            }else{
                dp[0][0][i]=1;
                distra_set.insert({1,0,0,i});
            }
        }

        int ans=INT_MAX;
        while(distra_set.size()>0){
            int x=(*distra_set.begin())[1];
            int y=(*distra_set.begin())[2];
            int dir=(*distra_set.begin())[3];
            distra_set.erase(distra_set.begin());

            if(x==n-1 and y==m-1){
                ans=min(ans,dp[x][y][dir]);
            }

            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx>=0 and ny>=0 and nx<n and ny<m){
                for(int i=0;i<4;i++){
                    int ex=0;
                    if(i+1 != grid[nx][ny]){
                        ex=1;
                    }

                    if(dp[x][y][dir]+ex < dp[nx][ny][i]){
                        dp[nx][ny][i]=dp[x][y][dir]+ex;
                        distra_set.insert({dp[nx][ny][i],nx,ny,i});
                    }
                }
            }
        }

        return ans;

    }
};