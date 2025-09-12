#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        ll cs=0,n=nums.size();
        map<ll,ll> help;
        help[0]=0;
        vector<ll> dp(n+1,1e10);
        dp[0]=0;

        for(ll i=1;i<=n;i++){
            cs=(cs+nums[i-1])%k;
            dp[i]=dp[i-1]+nums[i-1];
            if(help.find(cs) != help.end()){
                dp[i]=min(dp[i],help[cs]);
                help[cs]=min(help[cs],dp[i]);
            }else{
                help[cs]=dp[i];
            }
        }

        return dp[n];   

    }
};