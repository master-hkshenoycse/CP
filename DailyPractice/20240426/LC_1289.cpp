#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> >dp(n,vector<int> (m,1e9));
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            if(i==0){
                for(int j=0;j<m;j++){
                    dp[i][j]=grid[i][j];
                }
            }else{

                for(int j=0;j<m;j++){
                    for(int k=0;k<m;k++){
                        if(j!=k){
                            dp[i][j]=min(dp[i][j],dp[i-1][k]+grid[i][j]);
                        }
                    }
                }

            }

            if(i==n-1){
                for(int j=0;j<m;j++){
                    ans=min(ans,dp[i][j]);
                }
            }
        }

        return ans;
    }
};