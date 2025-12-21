#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        ll n=nums.size();
        ll max_ele = *max_element(nums.begin(),nums.end());
        ll msb = log2(max_ele);
        ll lim = (1ll<<(msb+1))-1;

        vector<ll> dp(lim+1,0);
        
        for(auto e:nums){
            dp[e]=e;
        }

        for(ll b=0;b<=msb;b++){
            for(ll mask = 0;mask <lim;mask++){
                if(mask & (1ll<<b))
                    dp[mask]=max(dp[mask],dp[mask^(1ll<<b)]);
            }
        }

        ll ans=0;
        for(auto e:nums){
            ans=max(ans,e*1ll*dp[lim^e]);
        }
        return ans;
        
    }
};