#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
ll fact[200005],inv_fact[200005];
ll pre=0;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }

    return res;
}

void pre_cum(){
    if(pre){
        return;
    }
    pre=1;
    fact[0]=1;
    inv_fact[0]=1;

    for(ll i=1;i<=200000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv_fact[i]=modpow(fact[i],mod-2);
    }
}
ll ncr(ll n,ll r){
    if(n<r){
        return 0;
    }

    ll ret=1;
    ret=fact[n];
    ret=(ret * inv_fact[r])%mod;
    ret=(ret * inv_fact[n-r])%mod;
    return ret;
}

class Solution {
public:
    ll calc(ll x){
        return (x*x+x)/2ll;
    }
    int distanceSum(int m, int n, int k) {
        swap(m,n);
        pre_cum();

        ll mul=ncr(n*m-2,k-2);

        ll ans=0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){

                //assume that 1 piece is placed at (i,j)
                ll d=(calc(i-1)+calc(n-i))*m;
                d%=mod;
                d=(d+(calc(j-1)+calc(m-j))*n);
                d%=mod;

                d=(d * mul)%mod;

                ans=(ans+d)%mod;


            }
        }

        ans=(ans * modpow(2,mod-2))%mod;
        return ans;
    }
};