#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countWays(string s1, string s2) {
        // code here
        int n=s1.size(),m=s2.size();
        
        vector<vector<int> > dp(n+1,vector<int> (m+1,0));
        
        
        int ans=0,mod=1e9+7;
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j];
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                }
                
            }
            
        }
        
        return dp[n][m];
    }
};