#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        if(n==0 or m==0){
            return 0;
        }
        
        vector<vector<int> > dp(n,vector<int> (m,0));
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    if(i==0 or j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        
        
        
        return ans;
    }
    
};