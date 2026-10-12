#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<ll> cnt(32,0);
        ll mod=1e9+7;
        
        for(auto e:nums){
            for(ll j=0;j<=30;j++){
                if(e & (1ll<<j)){
                    cnt[j]++;
                }
            }
        }
        
        vector<ll> vals(k,0);
        for(ll i=30;i>=0;i--){
            ll sz=min(k*1ll,cnt[i]);
            for(ll j=0;j<sz;j++){
                vals[j]+=(1ll<<i);
            }
        }
        
        ll ans=0;
        for(ll i=0;i<k;i++){
            ans=ans+(vals[i]*vals[i])%mod;
            ans%=mod;
        }
        return ans;
        
    }
};