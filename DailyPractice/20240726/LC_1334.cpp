#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > dp(n,vector<int> (n,1e9));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }

        for(auto e:edges){
            dp[e[0]][e[1]]=min(dp[e[0]][e[1]],e[2]);
            dp[e[1]][e[0]]=min(dp[e[1]][e[0]],e[2]);
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        int sol=-1,cnt=INT_MAX;

        for(int i=0;i<n;i++){
            int curr_cnt=0;
            for(int j=0;j<n;j++){
                if(dp[i][j]<=distanceThreshold){
                    curr_cnt++;
                }
            }

            if(curr_cnt<=cnt){
                cnt=curr_cnt;
                sol=i;
            }
        }

        return sol;
    }
};