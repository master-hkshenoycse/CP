#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        ll n=nums.size();
        ll m=target.size();
        ll lim=(1<<m);
        vector<ll> dp(lim,1e18),lcm_comb(lim);
        dp[0]=0;

        for(ll j=1;j<lim;j++){
            ll lc=1;
            for(ll k=0;k<m;k++){
                if(j & (1ll<<k)){
                    lc=(lc*target[k])/__gcd(lc,target[k]*1ll);
                }
            }
            lcm_comb[j]=lc;
        }


        for(ll i=0;i<n;i++){
            vector<ll> tmp(lim,1e18);
            for(ll j=1;j<lim;j++){
                ll ops=((nums[i]*1ll+lcm_comb[j]-1)/lcm_comb[j])*lcm_comb[j]-nums[i];
                for(ll k=0;k<lim;k++){
                    if(dp[k]<1e18){
                        tmp[j|k]=min(tmp[j|k],dp[k]+ops);
                    }
                }
            }

            for(ll j=0;j<lim;j++){
                dp[j]=min(dp[j],tmp[j]);
            }
        }
        return dp[lim-1];
    }
};