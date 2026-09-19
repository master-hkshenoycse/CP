#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fact[500005],inv_fact[500005];
ll prec=0,mod=1e9+7;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2)
            res=(res*a)%mod;
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void pre_cum(){
    if(prec)
        return;

    prec=1;
    fact[0]=1;
    inv_fact[0]=1;

    for(int i=1;i<=500000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv_fact[i]=modpow(fact[i],mod-2);
    }
}
ll ncr(ll n,ll r){
    if(r>n)
        return 0;
    
    ll ret=fact[n];
    ret=(ret * inv_fact[r])%mod;
    ret=(ret * inv_fact[n-r])%mod;
    return ret;
}
class Solution {
public:
    int countValidSequences(int n, int k) {
        pre_cum();
        ll overall=ncr(n-1,k-1);
        ll extra=(n-k);
        if(extra%2==0){
            overall-=ncr((n-k)/2+k-1,k-1);
            overall=(overall+mod)%mod;
        }
        return overall;
    }
};