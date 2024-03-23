#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod=1e9+7;
        vector<int> dp(k+1,0);
        dp[0]=1;

        for(int i=1;i<=k;i++){
            dp[i]=(dp[i]+dp[i-1])%mod;
        }


        for(int i=1;i<=n;i++){
            //ith element can be at position from 1 to i-1
            // at position 1 it will add i-1 to inversions, at position i it will add 0 to inversions 

            vector<int> tmp(k+1,0);
            for(int j=0;j<=k;j++){
                // to get j inversions at position i
                int lo=max(0,j-(i-1));
                int hi=j;
                int c_sum=dp[hi];
                if(lo-1>=0){
                    c_sum=(c_sum-dp[lo-1]+mod)%mod;
                }
                tmp[j]=c_sum;
            }

            for(int j=0;j<=k;j++){
                dp[j]=tmp[j];
                if(j-1>=0){
                    dp[j]=(dp[j]+dp[j-1])%mod;
                }
            }

        }

        int ans=dp[k];
        if(k-1>=0){
            ans=(ans-dp[k-1]+mod)%mod;
        }
        return ans;
        
    }
};