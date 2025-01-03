#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fact[100005];
ll inv_fact[100005];
ll is_done=0;
ll mod=1e9+7;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        n/=2;
        a=(a * a)%mod;
    }
    return res;
}
void pre_cum(){

    if(is_done){
        return;
    }

    is_done=1;
    fact[0]=1;
    inv_fact[0]=1;

    for(ll i=1;i<=100000;i++){
        fact[i]=(fact[i-1] * i)%mod;
        inv_fact[i]=modpow(fact[i],mod-2);
    }
}

ll ncr(ll n,ll r){
    if(n<r){
        return 0;
    }

    ll ret=fact[n];
    ret=(ret * inv_fact[r])%mod;
    ret=(ret * inv_fact[n-r])%mod;
    return ret;
}
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        pre_cum();
        ll ans=ncr(n-1,k);
        ans=(ans * m)%mod;
        ans=(ans * modpow(m-1,n-k-1))%mod;
        return ans;

    }
};