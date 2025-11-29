#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
           int n=grid.size(),m=grid[0].size();
        vector<vector<int> > dp[n];
        for(int i=0;i<n;i++){
            dp[i]=vector<vector<int> >(m,vector<int> (k,0));
        }
        int mod=1e9+7;
        
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0){
                    continue;
                }
                
                for(int x=0;x<k;x++){
                    if(i-1>=0){
                        dp[i][j][(x+grid[i][j])%k]=(dp[i][j][(x+grid[i][j])%k]+dp[i-1][j][x])%mod;
                    }
                    
                    if(j-1>=0){
                        dp[i][j][(x+grid[i][j])%k]=(dp[i][j][(x+grid[i][j])%k]+dp[i][j-1][x])%mod;
                    }
                    
                }
            }
        }
        
        return dp[n-1][m-1][0];
    }
};