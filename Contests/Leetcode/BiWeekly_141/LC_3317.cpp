#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll fact[2005],inv_fact[2005];
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

    void pre_cum(){
        fact[0]=1;
        inv_fact[0]=1;
        for(ll i=1;i<=2000;i++){
            fact[i]=(fact[i-1]*i)%mod;
            inv_fact[i]=modpow(fact[i],mod-2);
        }
    }
    ll ncr(ll n,ll r){
        if(r>n){
            return 0;
        }

        ll ret=fact[n];
        ret=(ret * inv_fact[n-r])%mod;
        ret=(ret * inv_fact[r])%mod;
        return ret;
    }
    ll get_ways(ll n,ll x,vector<vector<ll> > &dp){
        if(x>n){
            return 0;
        }
        if(n==0 || x==0){
            if(x==0 and n==0)return 1;
            return 0;

        }

        if(dp[n][x] != -1){
            return dp[n][x];
        }
        ll res=0;
        res=(res+get_ways(n-1,x,dp)*x)%mod;
        res=(res+get_ways(n-1,x-1,dp))%mod;
        return dp[n][x]=res;
    }
    int numberOfWays(int n, int x, int y) {
        pre_cum();
        ll ans=0;
        vector<vector<ll> > dp(n+1,vector<ll> (x+1,-1));

        for(ll i=1;i<=x;i++){
            ll ways_grp=get_ways(n,i,dp);
            ways_grp=(ways_grp * fact[i])%mod;
            ways_grp=(ways_grp * ncr(x,i))%mod;
            ll points_ways=modpow(y,i);
            ans=ans+(points_ways*ways_grp);
            ans%=mod;
        }

        return ans;

    }
};