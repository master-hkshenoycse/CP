#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDays(int n) {

        vector<int> dp(n+1,1e9);
        dp[0]=0;

        for(int i=1;i<=n;i++){
            int streak=1;
            for(int s=0;s+streak<=i;streak++){
                s=s+streak;
                int rem=i-s;
                if(rem==0)
                    dp[i]=min(dp[i],dp[rem]+streak);
                else
                    dp[i]=min(dp[i],dp[rem]+streak+1);
            }
            
        }

        return dp[n];
    }
};