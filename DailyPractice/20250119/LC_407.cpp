#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(),m=heightMap[0].size(),h_max=0;
        vector<vector<int> > vis(n,vector<int> (m,0));

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > > pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    pq.push({heightMap[i][j],i,j});
                    vis[i][j]=1;
                }
            }
        }

        int ans=0;
        while(pq.size()>0){
            int x=pq.top()[1];
            int y=pq.top()[2];
            int h=pq.top()[0];
            pq.pop();
            ans=ans+max(0,h_max-h);

            h_max=max(h_max,h);

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<m and vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    pq.push({heightMap[nx][ny],nx,ny});
                }
            }
        }

        return ans;

        
    }
};