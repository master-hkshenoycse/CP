#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        ll n=nums.size();
        vector<vector<ll> > dp(n+1,vector<ll> (2,-1e18));
        dp[0][0]=0;

        for(ll i=1;i<=n;i++){
            if(s[i-1]=='1'){
                dp[i][1]=max(dp[i-1][0],dp[i-1][1])+nums[i-1];
                
                if(i-2>=0)
                    dp[i][0]=dp[i-1][0]+nums[i-2];
                
            }else{
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            }   
        }

        return max(dp[n][0],dp[n][1]);
    }
};