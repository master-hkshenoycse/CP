#include<bits/stdc++.h>
using namespace std;
/* simple bfs based solution*/

class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    int get_distance(int sx,int sy,int ex,int ey,vector<vector<int>>& forest){
        int n=forest.size(),m=forest[0].size();
        vector<vector<int> > dp(n,vector<int> (m,INT_MAX));
        
        queue<pair<int,int> > q;
        q.push({sx,sy});
        dp[sx][sy]=0;

        while(q.size()>0){
            int x=q.front().first;
            int y=q.front().second;

            if(x==ex and y==ey){
                return dp[x][y];
            }
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and forest[nx][ny]>0 and dp[nx][ny]>dp[x][y]+1){
                    dp[nx][ny]=dp[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        return INT_MAX;
            
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int> > locations;
        
        int n=forest.size(),m=forest[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1){
                    locations.push_back({forest[i][j],i,j});
                }
            }
        }

        sort(locations.begin(),locations.end());
        int ans=0,px=0,py=0;
        
        for(auto l:locations){
            int d=get_distance(px,py,l[1],l[2],forest);
            if(d==INT_MAX){
                return -1;
            }
            ans=ans+d;
            px=l[1];
            py=l[2];
        }

        return ans;
    }
};