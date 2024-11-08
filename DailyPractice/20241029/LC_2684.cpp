#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > dp(n,vector<int> (m,INT_MIN));
        int ans=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(j==0){
                    dp[i][j]=0;
                }else{
                    if(grid[i][j]>grid[i][j-1]){
                        dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
                    }
                    
                    
                    if(i-1>=0 and grid[i][j]>grid[i-1][j-1]){
                        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                    }
                    
                    
                    if(i+1<n and grid[i][j]>grid[i+1][j-1]){
                        dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
                    }
                    
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        
        return ans;
    }
};