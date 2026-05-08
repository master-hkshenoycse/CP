#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define map unordered_map
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2)res=(res*a)%mod;
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    ll get_b(ll val){
        ll b=0;
        while((1ll<<b)<=val){
            b++;
        }
        return b;
    }
    int countEffective(vector<int>& nums) {
        ll tot_or=0,n=nums.size();
        for(auto e:nums){
            tot_or=(tot_or | e);
        }

        ll b=get_b(tot_or);
        ll lim=(1ll<<b)-1;
    
        vector<ll> cnt(lim+1,0),ways(lim+1,0);
        for(auto e:nums)
            cnt[e]++;
        
        for(ll i=0;i<=b;i++){
            for(ll j=0;j<=tot_or;j++){
                if(j & (1ll<<i)){
                    cnt[j]=(cnt[j]+cnt[(j ^ (1ll<<i))])%mod;
                }
            }
        }

        for(ll i=0;i<=tot_or;i++)
            ways[i]=modpow(2,cnt[i]);

        for(ll i=0;i<=b;i++){
            for(ll j=0;j<=tot_or;j++){
                if(j & (1ll<<i)){
                    ways[j]=(ways[j]-ways[(j ^ (1ll<<i))]+mod)%mod;
                }
            }
        }

        ll tot=modpow(2,n);
        ll good=ways[tot_or];
        ll ret=(tot-good+mod)%mod;
        return ret;

    }
};