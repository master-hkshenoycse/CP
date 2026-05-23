#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        
        for(auto r:restrictions)
            dp[r[0]]=r[1];

        
        for(int i=1;i<n;i++)
            dp[i]=min(dp[i],dp[i-1]+diff[i-1]);
        
        for(int i=n-2;i>=0;i--)
            dp[i]=min(dp[i],dp[i+1]+diff[i]);

        int ret=0;

        for(int i=0;i<n;i++)
            ret=max(ret,dp[i]);

        return ret;
        
    }
};