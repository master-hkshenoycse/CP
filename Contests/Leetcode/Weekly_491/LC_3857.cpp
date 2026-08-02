#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(int n) {
        vector<int> dp(n+1,INT_MAX);

        dp[0]=0;
        dp[1]=0;

        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=min(dp[i],dp[j]+dp[i-j]+j*(i-j));
            }
        }

        return dp[n];
        
    }
};