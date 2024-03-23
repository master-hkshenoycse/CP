#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res*a)%mod;
            }
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    int sumOfPower(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<vector<ll> > dp(n+1,vector<ll> (k+1,0));
        dp[0][0]=1;
        
        for(ll i=0;i<n;i++){
            ll e=nums[i];
            
            for(ll l=n;l>=1;l--){
                for(ll j=0;j<=k;j++){
                    if(j-e>=0){
                        dp[l][j]=(dp[l][j]+dp[l-1][j-e])%mod;
                    }
                }
            }
            
        }
        
        
        
        ll ans=0;
        for(ll i=1;i<=n;i++){
            //subsequnec of length i with some equal to k;
            //remainig element n-i
            
            //cout<<i<<" "<<dp[i][k]<<endl;
            ll mul=modpow(2,n-i);
            ans=ans+(mul * dp[i][k])%mod;
            ans%=mod;
        }
        
        return ans;
    }
};