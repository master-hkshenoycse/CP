#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    struct dist_parity{
        ll dist;
        int x, y, parity;
        bool operator>(const dist_parity &oth) const{
            return dist > oth.dist;  
        }
    };  
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<dist_parity,vector<dist_parity>, greater<dist_parity> >pq;
        pq.push({1,0,0,0});
        vector<vector<vector<ll> > > dp(m,vector<vector<ll> > (n,vector<ll> (2,1e18)));
        dp[0][0][0]=1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(pq.size()>0){

            ll dist=pq.top().dist;
            int x=pq.top().x;
            int y=pq.top().y;
            int parity=pq.top().parity;

            pq.pop();
            
            if(dp[x][y][parity]!=dist)
                continue;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<m && ny<n && nx>=0 && ny>=0){
                    ll cost=(nx+1)*(ny+1)+dist;
                    if(parity==1 && (dx[i]>0 || dy[i]>0))
                        cost+=penalty[x][y];
                    if(parity==0 && (dx[i]<0 || dy[i]<0))
                        cost+=penalty[x][y];
                    
                    if(cost<dp[nx][ny][1-parity]){
                        dp[nx][ny][1-parity]=cost;
                        pq.push({dp[nx][ny][1-parity],nx,ny,1-parity});
                    }
                }
            }

            if(dp[x][y][1-parity]>dp[x][y][parity]+penalty[x][y]){
                dp[x][y][1-parity]=dp[x][y][parity]+penalty[x][y];
                pq.push({dp[x][y][1-parity],x,y,1-parity});
            }
        }

        
        return min(dp[m-1][n-1][0],dp[m-1][n-1][1]);    
    }
};