#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        int mod=1e9+7;
        
        //no of people who know secret added on day i from day j;
        
        for(int i=1;i<=n;i++){
            for(int j=delay;j<forget;j++){
                if(j+i<=n)dp[j+i]=(dp[j+i]+dp[i])%mod;
            }
        }
        
        int ans=0;
        
        for(int i=1;i<=n;i++){
            if(i+forget>n){
                ans=ans+dp[i];
                ans%=mod;
            }
        }
        
        return ans;
    
        
    }
};