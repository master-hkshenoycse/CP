#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll fact[85],inv_fact[85];
    ll dp[45][10][401];
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res * a)%mod;
            }
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    ll solve(ll len,ll st,ll rem,vector<ll> &cnt,ll len_lim){
        
        if(len==len_lim){
            
            if(rem>0){
                return 0;
            }
            
            ll ret=1;
            for(ll i=st;i<=9;i++){
                ret=(ret * inv_fact[cnt[i]])%mod;
            }

            return ret;
        }

        if(st>9){
            return 0;
        }

        if(dp[len][st][rem] != -1){
            return dp[len][st][rem];
        }

        ll res=0;

        for(ll j=0;j<=cnt[st];j++){
            if(j*st<=rem and j+len<=len_lim){
                ll tmp= (inv_fact[j] * inv_fact[cnt[st]-j])%mod;
                tmp=(tmp * solve(j+len,st+1,rem-j*st,cnt,len_lim))%mod;
                res=(res+tmp)%mod;
            }
        }

        return dp[len][st][rem]=res;
    }
    int countBalancedPermutations(string num) {
        ll n=num.size();

        fact[0]=1;
        inv_fact[0]=1;
        for(ll i=1;i<=n;i++){
            fact[i]=(fact[i-1]*i)%mod;
            inv_fact[i]=modpow(fact[i],mod-2);
        }
    
        int s=0;
        vector<ll> cnt(10,0);
        for(int i=0;i<n;i++){
            s=s+(num[i]-'0');
            cnt[num[i]-'0']++;
        }
        if(s%2){
            return 0;
        }


        memset(dp,-1,sizeof(dp));

        ll res=solve(0,0,s/2,cnt,n/2);        
        
        res=(res*fact[n/2])%mod;
        res=(res*fact[n-n/2])%mod;

        return res;
    }
};