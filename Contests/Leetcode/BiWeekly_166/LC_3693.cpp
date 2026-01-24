#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int len=1;len<=min(i,3);len++){
                dp[i]=min(dp[i],dp[i-len]+len*len+costs[i-1]);
            }
        }
        return dp[n];
    }
};