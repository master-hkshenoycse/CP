#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int almostPalindromic(string s) {
        int res=2, n=s.size();
        vector<vector<int> > dp(n,vector<int> (n,0));

        for(int i=0;i<n-1;i++)
            dp[i][i+1]=(s[i] != s[i+1]);
 
        for(int len=3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                else
                    dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
                
                if(dp[i][j]<=1)
                    res=max(res,len);
            }
        }

        return res;        
    }
};