#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isp[2005][2005];
    int maxPalindromes(string s, int k) {
        int n=s.size();
        for(int i=1;i<=n;i++){
            isp[i][i]=1;
            if(i+1<=n and s[i-1]==s[i]){
                isp[i][i+1]=1;
            }
        }
        
        for(int l=3;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int st=i;
                int en=i+l-1;
                if(s[st-1]==s[en-1] and isp[st+1][en-1]){
                    isp[st][en]=1;
                }
            }
        }
        
        vector<int> dp(n+1,0);
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            for(int j=k;j<=i;j++){
                int en=i-j;
                if(dp[en]>=0 and isp[en+1][i]==1){
                    dp[i]=max(dp[i],dp[en]+1);
                }
            }
        }
        
        
        
        
        return dp[n];
        
        
        
    }
};