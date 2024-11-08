#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        vector<vector<int> > dp(n,vector<int> (m,2e9));
        dp[0][0]=0;
        set<vector<int> > s;
        s.insert({dp[0][0],0,0});

        while(s.size()>0){
            auto it=*s.begin();
            int x=it[1];
            int y=it[2];
            int d=it[0];
            s.erase(it);
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<m){
                    int nd=max(d+1,moveTime[nx][ny]+1);
                    if(nd < dp[nx][ny]){
                        dp[nx][ny]=nd;
                        s.insert({dp[nx][ny],nx,ny});
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }   
};