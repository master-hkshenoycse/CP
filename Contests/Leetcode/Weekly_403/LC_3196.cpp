#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> dp(n+1,-1e18);
        dp[0]=0;
        
        for(ll i=1;i<=n;i++){
            dp[i]=dp[i-1]+nums[i-1];
            if(i-2>=0){
                dp[i]=max(dp[i],dp[i-2]+nums[i-2]-nums[i-1]);
            }
        }
        
        return dp[n];
    }
};