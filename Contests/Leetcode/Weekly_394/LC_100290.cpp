#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > dp(m+1,vector<int> (10,1e9));
        
        for(int i=0;i<=9;i++){
            dp[0][i]=0;
        }
        int ans=1e9;
        
        for(int i=1;i<=m;i++){
            vector<int> cnt(10,0);
            for(int j=0;j<n;j++){
                cnt[grid[j][i-1]]++;
            }
            
            
            for(int k=0;k<=9;k++){

                for(int p=0;p<=9;p++){
                    if(k!=p){
                        dp[i][k]=min(dp[i][k],dp[i-1][p]+(n-cnt[k]));
                    }
                }
                
                if(i==m){
                    ans=min(ans,dp[i][k]);
                }
            }
        }
        
        return ans;
        
        
    }
};