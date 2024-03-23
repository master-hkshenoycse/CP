#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int subsequenceCount(string S, string T){
      int mod=1e9+7;
      //Your code here
      int n=S.size(),m=T.size();
      vector<vector<int> >dp(n+1,vector<int>(m+1,0));
      dp[0][0]=1;
      
      for(int i=1;i<=n;i++){
          dp[i][0]=1;
          for(int j=1;j<=m;j++){
              dp[i][j]=dp[i-1][j];
              if(S[i-1]==T[j-1]){
                  dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
              }
          }
      }
      return dp[n][m];
    }
};